/*
 * safety.h
 *
 *  Created on: 21 de jan de 2025
 *      Author: ramon.martins
 */

#ifndef SAFETY_INCLUDE_SAFETY_H_
#define SAFETY_INCLUDE_SAFETY_H_

#include <stdint.h>

/**
 * @addtogroup CPU1
 * @{
 */

/**
 * @addtogroup safety_support_cpu1
 * @{
 */

extern _Noreturn void bsp_global_assert(char const * const module, uint16_t id);

extern uint64_t bsp_complementary_assert_data[2];

#define S_DEFINE_THIS_MODULE(name_) \
    static char const s_module_name_[] = name_;

/**
 * @brief Macro used to call the global assert, with automatic module filling.
 *
 * @param id_   The error number that triggered the assert must be unique for each assert in the module.
 * @param expr_ Boolean expression that must be true for the code to be functioning normally.
 */

#define S_ASSERT(id_, expr_)  \
    ((expr_) ? ((void)0) : bsp_global_assert(&s_module_name_[0], (id_)))

/**
 * @brief Macro que deve ser utilizada para verificar parâmentros de entrada.
 *
 * @param id_   The error number that triggered the assert must be unique for each assert in the module.
 * @param expr_ Boolean expression that must be true for the code to be functioning normally.
 */

#define S_REQUIRE(id_, expr_) \
    S_ASSERT(id_, expr_)

/**
 * @brief Macro que deve ser utilizada para verificar condições de saída.
 *
 * @param id_   The error number that triggered the assert must be unique for each assert in the module.
 * @param expr_ Boolean expression that must be true for the code to be functioning normally.
 */

#define S_ENSURE(id_, expr_) \
    S_ASSERT(id_, expr_)

/**
 * @}
 */

/**
 * @}
 */

#endif /* SAFETY_INCLUDE_SAFETY_H_ */
