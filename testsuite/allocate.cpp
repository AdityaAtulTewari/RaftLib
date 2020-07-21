#include <cassert>
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <raft>
#include <raftio>
#include "generate.tcc"


template< typename A, typename B, typename C > class Sum : public raft::kernel
{
public:
   Sum() : raft::kernel()
   {
      input.addPort< A >( "input_a" );
      input.addPort< B >( "input_b" );
      output.addPort< C  >( "sum" );
   }
   
   virtual raft::kstatus run()
   {
      A a;
      B b;
      raft::signal  sig_a( raft::none  ), sig_b( raft::none );
      input[ "input_a" ].pop( a, &sig_a );
      input[ "input_b" ].pop( b, &sig_b );
      assert( sig_a == sig_b );
      C c( a + b );
      output[ "sum" ].push( c , sig_a );
      if( sig_b == raft::eof )
      {
         return( raft::stop );
      }
      return( raft::proceed );
   }

};


int
main( )
{
   using type_t = std::int64_t;
   using gen    = raft::test::generate< type_t >;
   using sum    = Sum< type_t, type_t, type_t >;
   using p_out  = raft::print< type_t, '\n' >;

   raft::map m;
   auto s( raft::kernel::make< sum >() );
   m += raft::kernel::make< gen >()  >> s[ "input_a" ];
   m += raft::kernel::make< gen >()  >> s[ "input_b" ];
   m += s >> raft::kernel::make< p_out >(); 
   m.exe();
   
   return( EXIT_SUCCESS );
}
