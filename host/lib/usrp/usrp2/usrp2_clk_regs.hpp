//
// Copyright 2010 Ettus Research LLC
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef INCLUDED_USRP2_CLK_REGS_HPP
#define INCLUDED_USRP2_CLK_REGS_HPP

#include <uhd/usrp/mboard_rev.hpp>
#include "usrp2_regs.hpp"

class usrp2_clk_regs_t {
public:
  usrp2_clk_regs_t(void) { ; }
  usrp2_clk_regs_t(uhd::usrp::mboard_rev_t hw_rev) {
    test = 0;
    fpga = 1;
    adc = (hw_rev.is_usrp2p()) ? 2 : 4;
    dac = 3;
    serdes = (hw_rev.is_usrp2p()) ? 4 : 2; //only used by usrp2+
    tx_db = (hw_rev.is_usrp2p()) ? 5 : 6;
    
    if(hw_rev.major() == 3) exp = 2;
    else if(hw_rev.major() >= 4) exp = 5;
    else if(hw_rev.major() > 10) exp = 6;
    
    rx_db = 7;
  }

  static int output(int clknum) { return 0x3C + clknum; }
  static int div_lo(int clknum) { return 0x48 + 2 * clknum; }
  static int div_hi(int clknum) { return 0x49 + 2 * clknum; }

  const static int acounter = 0x04;
  const static int bcounter_msb = 0x05;
  const static int bcounter_lsb = 0x06;
  const static int pll_1 = 0x07;
  const static int pll_2 = 0x08;
  const static int pll_3 = 0x09;
  const static int pll_4 = 0x0A;
  const static int ref_counter_msb = 0x0B;
  const static int ref_counter_lsb = 0x0C;
  const static int pll_5 = 0x0D;
  const static int update = 0x5A;

  int test;
  int fpga;
  int adc;
  int dac;
  int serdes;
  int exp;
  int tx_db;
  int rx_db;
};

#endif //INCLUDED_USRP2_CLK_REGS_HPP