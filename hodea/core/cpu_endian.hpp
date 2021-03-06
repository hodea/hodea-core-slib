// Copyright (c) 2017, Franz Hollerer.
// SPDX-License-Identifier: MIT

/**
 * Convert between specified byte order and CPU byte order.
 *
 * This module provides functions to convert an unsigned data type
 * with given size and byte order into the same type representing
 * the value in CPU byte order, and vice versa.
 *
 * \note
 * We expect the CPU to user either big or little endian format. We
 * don't support PDP endian.
 *
 * \author f.hollerer@hodea.org
 */
#if !defined HODEA_CPU_ENDIAN_HPP
#define HODEA_CPU_ENDIAN_HPP

#include <hodea/core/cstdint.hpp>
#include <hodea/core/uswap.hpp>

namespace hodea {

/*
 * We use predefined macros to determine the endianness of the target CPU.
 * Unfortunately, this predefined macros vary from compiler to compiler.
 * If we are unable to determine the endianness, the user must pass
 * the macro HODEA_IS_CPU_LE with its value set to  true or false 
 * to the compiler via command line.
 */

#if defined __GNUC__ || defined __clang__

    /*
     * GCC and LLVM/clang provide __BYTE_ORDER__, __ORDER_LITTLE_ENDIAN__
     * and __ORDER_BIG_ENDIAN__.
     */
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        #define HODEA_IS_CPU_LE true
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        #define HODEA_IS_CPU_LE false
    #endif

#elif defined __CC_ARM

    /*
     * ARM Compiler V5 or older.
     */
    #if defined __BIG_ENDIAN
        #define HODEA_IS_CPU_LE false
    #else
        #define HODEA_IS_CPU_LE true
    #endif

#elif defined __ICCARM__

    /*
     * IAR Compiler
     */
    #if __LITTLE_ENDIAN__ == 0
        #define HODEA_IS_CPU_LE false
    #elif __LITTLE_ENDIAN__ == 1
        #define HODEA_IS_CPU_LE true
    #endif

#endif

#if !defined HODEA_IS_CPU_LE
#error "Unable to detect cpu endianness via predefined macros."
#error "Please provide HODEA_IS_CPU_LE = true or false via command line."
#endif

#define HODEA_IS_CPU_BE (!HODEA_IS_CPU_LE)

/**
 * Test if CPU uses the little endian format.
 */
constexpr bool is_cpu_le()
{
    return HODEA_IS_CPU_LE;
}

/**
 * Test if CPU uses the big endian format.
 */
constexpr bool is_cpu_be()
{
    return HODEA_IS_CPU_BE;
}

/**
 * Convert unsigned 16 bit value in CPU byte order to little endian.
 */
static inline constexpr uint16_t cpu_to_le16(uint16_t x)
{
    return (is_cpu_le() ? x : uswap16(x));
}

/**
 * Convert unsigned 32 bit value in CPU byte order to little endian.
 */
static inline constexpr uint32_t cpu_to_le32(uint32_t x)
{
    return (is_cpu_le() ? x : uswap32(x));
}

/**
 * Convert unsigned 64 bit value in CPU byte order to little endian.
 */
static inline constexpr uint64_t cpu_to_le64(uint64_t x)
{
    return (is_cpu_le() ? x : uswap64(x));
}

/**
 * Convert unsigned 16 bit value in CPU byte order to big endian.
 */
static inline constexpr uint16_t cpu_to_be16(uint16_t x)
{
    return (is_cpu_be() ? x : uswap16(x));
}

/**
 * Convert unsigned 32 bit value in CPU byte order to big endian.
 */
static inline constexpr uint32_t cpu_to_be32(uint32_t x)
{
    return (is_cpu_be() ? x : uswap32(x));
}

/**
 * Convert unsigned 64 bit value in CPU byte order to big endian.
 */
static inline constexpr uint64_t cpu_to_be64(uint64_t x)
{
    return (is_cpu_be() ? x : uswap64(x));
}

/**
 * Convert unsigned 16 bit value in little endian to CPU byte order.
 */
static inline constexpr uint16_t le16_to_cpu(uint16_t x)
{
    return cpu_to_le16(x);
}

/**
 * Convert unsigned 32 bit value in little endian to CPU byte order.
 */
static inline constexpr uint32_t le32_to_cpu(uint32_t x)
{
    return cpu_to_le32(x);
}

/**
 * Convert unsigned 64 bit value in little endian to CPU byte order.
 */
static inline constexpr uint64_t le64_to_cpu(uint64_t x)
{
    return cpu_to_le64(x);
}

/**
 * Convert unsigned 16 bit value in big endian to CPU byte order.
 */
static inline constexpr uint16_t be16_to_cpu(uint16_t x)
{
    return cpu_to_be16(x);
}

/**
 * Convert unsigned 32 bit value in big endian to CPU byte order.
 */
static inline constexpr uint32_t be32_to_cpu(uint32_t x)
{
    return cpu_to_be32(x);
}

/**
 * Convert unsigned 64 bit value in big endian to CPU byte order.
 */
static inline constexpr uint64_t be64_to_cpu(uint64_t x)
{
    return cpu_to_be64(x);
}

} // namespace hodea

#endif /*!HODEA_CPU_ENDIAN_HPP */
