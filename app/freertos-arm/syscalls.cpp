/////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author Kuba Sejdak
/// @copyright BSD 2-Clause License
///
/// Copyright (c) 2017-2019, Kuba Sejdak <kuba.sejdak@gmail.com>
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
#include <sys/time.h>
#include <sys/types.h>

#include <array>
#include <cstddef>
#include <type_traits>

/// Implements the console capability by defining what should happen with messages intended for stdout.
/// @param message      Message to be printed.
/// @param size         Size of the message.
/// @return Number of processed bytes.
/// @note This function is called by the _write() syscall.
extern int consolePrint(const char* message, std::size_t size);

extern "C" {

// NOLINTNEXTLINE
caddr_t _sbrk(intptr_t increment)
{
    constexpr int cBufferSize = 2 * 1024;
    static std::array<char, cBufferSize> buffer;
    static std::size_t offset = 0;

    std::size_t prevOffset = offset;

    if (offset + increment > buffer.size())
        return nullptr;

    offset += increment;
    return reinterpret_cast<caddr_t>(&buffer.at(prevOffset));
}

// NOLINTNEXTLINE
int _write(int /*unused*/, const void* buf, size_t count)
{
    return consolePrint(reinterpret_cast<const char*>(buf), count);
}

size_t fwrite(const void* ptr, size_t /*unused*/, size_t nmemb, FILE* /*unused*/)
{
    return _write(0, std::remove_const_t<char*>(ptr), nmemb);
}

// NOLINTNEXTLINE
int _gettimeofday(struct timeval* tp, void* /*unused*/)
{
    if (tp != nullptr) {
        constexpr std::uint32_t cUsInMs = 1000;
        constexpr std::uint32_t cUsInSec = 1000000;
        auto nowUs = static_cast<std::uint32_t>(xTaskGetTickCount()) * cUsInMs;
        auto nowSec = nowUs / cUsInSec;
        tp->tv_usec = nowUs - (nowSec * cUsInSec);
        tp->tv_sec = nowSec;
    }

    return 0;
}

} // extern "C"
