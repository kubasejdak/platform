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

#include "stm32f4xx_usart.h"

#include <sys/stat.h>
#include <sys/types.h>

#include <array>
#include <csignal>

extern "C" {

// NOLINTNEXTLINE
caddr_t _sbrk(intptr_t increment)
{
    constexpr int cPrintfBufferSize = 2 * 1024;
    static std::array<char, cPrintfBufferSize> buffer;
    static std::size_t offset = 0;

    std::size_t prevOffset = offset;

    if (offset + increment > buffer.size())
        return nullptr;

    offset += increment;
    return reinterpret_cast<caddr_t>(&buffer[prevOffset]);
}

// NOLINTNEXTLINE
int _write(int, const void* buf, size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        while (USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET) { // NOLINT
        }
        USART_SendData(UART4, reinterpret_cast<char*>(&buf)[i]); // NOLINT
    }

    return count;
}

// clang-format off
int _open(const char* /*unused*/, int /*unused*/, mode_t /*unused*/) { return -1; }    // NOLINT
int _close(int /*unused*/)                                           { return -1; }    // NOLINT
int _read(int /*unused*/, void* /*unused*/, size_t /*unused*/)       { return -1; }    // NOLINT
off_t _lseek(int /*unused*/, off_t /*unused*/, int /*unused*/)       { return -1; }    // NOLINT
void _exit(int /*unused*/)                                           { while (true); } // NOLINT
int _fstat(int /*unused*/, struct stat* /*unused*/)                  { return 0; }     // NOLINT
int _isatty(int /*unused*/)                                          { return 1; }     // NOLINT
int _kill(int /*unused*/, int /*unused*/)                            { return -1; }    // NOLINT
pid_t _getpid()                                                      { return 1; }     // NOLINT
// clang-format on

} // extern "C"
