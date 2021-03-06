/*
 * Copyright (c) 2017-2020 Arm Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef ARM_COMPUTE_NERESHAPELAYERKERNEL_H
#define ARM_COMPUTE_NERESHAPELAYERKERNEL_H

#include "src/core/NEON/INEKernel.h"
#include "src/core/NEON/INESimpleKernel.h"

namespace arm_compute
{
// Forward declarations
class ITensor;

/** Interface for the kernel to perform tensor reshaping */
class NEReshapeLayerKernel : public INEKernel
{
public:
    const char *name() const override
    {
        return "NEReshapeLayerKernel";
    }
    /** Default constructor */
    NEReshapeLayerKernel() = default;
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    NEReshapeLayerKernel(const NEReshapeLayerKernel &) = delete;
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    NEReshapeLayerKernel &operator=(const NEReshapeLayerKernel &) = delete;
    /** Allow instances of this class to be moved */
    NEReshapeLayerKernel(NEReshapeLayerKernel &&) = default;
    /** Allow instances of this class to be moved */
    NEReshapeLayerKernel &operator=(NEReshapeLayerKernel &&) = default;
    /** Default destructor */
    ~NEReshapeLayerKernel() = default;
    /** Set the input and output info of the kernel
     *
     * @param[in]  input  Source tensor info. Data type supported: All
     * @param[out] output Destination tensor info. Data type supported: Same as @p input
     */
    void configure(const ITensorInfo *input, ITensorInfo *output);

    /** Static function to check if given info will lead to a valid configuration of @ref NEReshapeLayerKernel
     *
     * @param[in] input  Source tensor info. Data type supported: All
     * @param[in] output Destination tensor info. Data type supported: Same as @p input
     *
     * @return a status
     */
    static Status validate(const ITensorInfo *input, const ITensorInfo *output);

    // Inherited methods overridden:
    void run_op(ITensorPack &tensors, const Window &window, const ThreadInfo &info) override;
};
} // namespace arm_compute
#endif /*ARM_COMPUTE_NERESHAPELAYERKERNEL_H */
