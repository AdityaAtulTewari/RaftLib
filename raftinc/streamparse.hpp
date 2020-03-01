/**
 * streamparse.hpp - 
 * @author: Jonathan Beard
 * @version: Thu Dec 29 05:52:20 2016
 * 
 * Copyright 2016 Jonathan Beard
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _STREAMPARSE_HPP_
#define _STREAMPARSE_HPP_  1

#include "parsemap.hpp"
#include "defs.hpp"
#include "raftmanip.hpp"
#include <memory>
#include "kernel_wrapper.hpp"

namespace raft
{
    class kernel;
}


/**
 * definitions:
 * RHS (right hand side) - refers to the expression to the
 * right  of the ">>" for example in "a >> b", so the RHS
 * is "b".
 * 
 * LHS (left hand side) - refers to the expression to the
 * left  of the ">>" for example in "a >> b", so the LHS
 * is "a".
 */

/**
 * #1 This section covers the baseic "a >> b" link modalities
 */
raft::parsemap_ptr operator >> ( raft::kernel &src         ,   raft::kernel &dst           );
/**
 * raft::kernel::make< type >( params ) >> b
 */
raft::parsemap_ptr operator >> ( raft::kernel_wrapper src ,   raft::kernel &dst           );
/**
 * a >> raft::kernel::make< type >( params )
 */
raft::parsemap_ptr operator >> ( raft::kernel &src         ,   raft::kernel_wrapper dst   );
/**
 * raft::kernel::make< type >( params ) >> raft::kernel::make< type >( params )
 */
raft::parsemap_ptr operator >> ( raft::kernel_wrapper src ,   raft::kernel_wrapper dst   );


/**
 * this section covers the continuation style where on 
 * the LHS there is a parsemap object and on the RHS 
 * there is a kernel, there should be one function here
 * for ever function in section #1 above.
 */
raft::parsemap_ptr operator >> ( raft::parsemap_ptr src ,   raft::kernel &dst           );
raft::parsemap_ptr operator >> ( raft::parsemap_ptr src ,   raft::kernel_wrapper dst    );




#endif /* END _STREAMPARSE_HPP_ */
