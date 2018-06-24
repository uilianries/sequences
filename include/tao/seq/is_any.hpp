// Copyright (c) 2015-2018 Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/sequences/

#ifndef TAO_SEQUENCES_INCLUDE_IS_ANY_HPP
#define TAO_SEQUENCES_INCLUDE_IS_ANY_HPP

#include "config.hpp"

#ifndef TAO_SEQUENCES_FOLD_EXPRESSIONS
#include "is_all.hpp"
#endif

#include <type_traits>

namespace tao
{
   namespace seq
   {

#ifdef TAO_SEQUENCES_FOLD_EXPRESSIONS

      template< bool... Bs >
      using is_any = std::integral_constant< bool, ( Bs || ... ) >;

#else

      template< bool... Bs >
      using is_any = std::integral_constant< bool, !is_all< !Bs... >::value >;

#endif

   }  // namespace seq

}  // namespace tao

#endif
