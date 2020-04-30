/////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author Kuba Sejdak
/// @copyright BSD 2-Clause License
///
/// Copyright (c) 2019-2020, Kuba Sejdak <kuba.sejdak@gmail.com>
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
///
/// 1. Redistributions of source code must retain the above copyright notice, this
///    list of conditions and the following disclaimer.
///
/// 2. Redistributions in binary form must reproduce the above copyright notice,
///    this list of conditions and the following disclaimer in the documentation
///    and/or other materials provided with the distribution.
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
/// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
/// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
/// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
/// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
/// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
/// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
/// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
/////////////////////////////////////////////////////////////////////////////////////

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <array>
#include <cstdlib>
#include <type_traits>

/// Main application entry point.
/// @param argc         Number of the commandline arguments.
/// @param argv         Array of commandline arguments containing argc strings.
/// @return Exit code of the application.
/// @note This function should be provided/implemented by the application.
// NOLINTNEXTLINE
extern int appMain(int argc, char* argv[]);

#if configSUPPORT_STATIC_ALLOCATION
extern "C" void vApplicationGetIdleTaskMemory(StaticTask_t** ppxIdleTaskTCBBuffer,
                                              StackType_t** ppxIdleTaskStackBuffer,
                                              uint32_t* pulIdleTaskStackSize)
{
    /* If the buffers to be provided to the Idle task are declared inside this
    function then they must be declared static – otherwise they will be allocated on
    the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task’s
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task’s stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

    #if configUSE_TIMERS
extern "C" void vApplicationGetTimerTaskMemory(StaticTask_t** ppxTimerTaskTCBBuffer,
                                               StackType_t** ppxTimerTaskStackBuffer,
                                               uint32_t* pulTimerTaskStackSize)
{
    /* If the buffers to be provided to the Timer task are declared inside this
    function then they must be declared static – otherwise they will be allocated on
    the stack and so not exists after this function exits. */
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

    /* Pass out a pointer to the StaticTask_t structure in which the Timer
    task’s state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task’s stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configTIMER_TASK_STACK_DEPTH is specified in words, not bytes. */
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}
    #endif
#endif

/// Default name that is passed to the application as argv[0].
constexpr const char* cMainThreadName = "appMain";

/// Wrapper thread that will execute the main application code.
static void mainThread(void* /*unused*/)
{
    std::array<char*, 1> appArgv = {std::remove_const_t<char*>(cMainThreadName)};
    appMain(appArgv.size(), appArgv.data());
}

/// Main executable entry point.
/// @return Exit code of the application.
/// @note This function passes one hardcoded commandline argument to the application, to fulfill the requirement
/// that argv[0] contains the name of the binary.
/// @note Depending on the value of the configSUPPORT_STATIC_ALLOCATION and configSUPPORT_DYNAMIC_ALLOCATION
/// macro definitions (which should be defined in the FreeRTOSConfig.h in the application code), this function creates
/// the application thread using static or dynamic API of the FreeRTOS threading module.
int main()
{
    TaskHandle_t thread = nullptr;
#if configSUPPORT_STATIC_ALLOCATION
    StaticTask_t threadBuffer{};
    std::array<StackType_t, configMINIMAL_STACK_SIZE> stack{};

    thread = xTaskCreateStatic(mainThread,
                               cMainThreadName,
                               configMINIMAL_STACK_SIZE,
                               nullptr,
                               tskIDLE_PRIORITY,
                               stack.data(),
                               &threadBuffer);
    if (thread == nullptr)
        return EXIT_FAILURE;

#elif configSUPPORT_DYNAMIC_ALLOCATION
    auto result
        = xTaskCreate(mainThread, cMainThreadName, configMINIMAL_STACK_SIZE, nullptr, tskIDLE_PRIORITY, &thread);
    if (result != pdPASS)
        return EXIT_FAILURE;
#endif

    vTaskStartScheduler();
    return EXIT_SUCCESS;
}
