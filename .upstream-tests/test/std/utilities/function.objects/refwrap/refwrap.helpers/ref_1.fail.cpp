//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <cuda/std/functional>

// reference_wrapper

// template <ObjectType T> reference_wrapper<T> ref(T& t);

// Don't allow binding to a temp

// XFAIL: c++98, c++03

// .fail. expects compilation to fail, but this would only fail at runtime with NVRTC
// UNSUPPORTED: nvrtc

#include <cuda/std/functional>

struct A {};

const A source() {return A();}

int main(int, char**)
{
    cuda::std::reference_wrapper<const A> r = cuda::std::ref(source());

  return 0;
}