/**
 * splitmethod.cpp - 
 * @author: Jonathan Beard
 * @version: Sat Jul 11 16:00:01 2020
 * 
 * Copyright 2020 Jonathan Beard
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
#include "splitmethod.hpp"


splitmethod::splitmethod( Port &port ) : _port( port ),
                                         begin( _port.begin() ),
                                         current( _port.begin() ),
                                         end( _port.end() )
{

}
