library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- 1879700 Xuhua Huang
-- inspired by:
-- https://startingelectronics.org/software/VHDL-CPLD-course/tut14-VHDL-adder/

entity fourBitAdder is
    Port ( NUM1 : in  STD_LOGIC_VECTOR (4 downto 0) := "00000";    -- 4-bit number
           NUM2 : in  STD_LOGIC_VECTOR (4 downto 0) := "00000";    -- 4-bit number
			  
			  SUM : buffer STD_LOGIC_VECTOR (4 downto 0);   -- 5 bit result

			  clk  : in  std_logic; -- using a clock as data trigger
			  
	ssd0  : out std_logic_vector(6 downto 0);    -- 7 bit decoded output.
	ssd1  : out std_logic_vector(6 downto 0);
	ssd2  : out std_logic_vector(6 downto 0);
  ssd3  : out std_logic_vector(6 downto 0)
	
	);
end fourBitAdder;

architecture Behavioral of fourBitAdder is
begin
			  
    SUM <= NUM1 + NUM2;

	 display_process : process (clk, NUM1, NUM2) --, lower, carry)
    begin
        if rising_edge(clk) then
            case NUM1(3 downto 0) is
            when "0000"=> ssd0 <="0000001";  -- '0'
            when "0001"=> ssd0 <="1001111";  -- '1'
            when "0010"=> ssd0 <="0010010";  -- '2'
            when "0011"=> ssd0 <="0000110";  -- '3'
            when "0100"=> ssd0 <="1001100";  -- '4'
            when "0101"=> ssd0 <="0100100";  -- '5'
            when "0110"=> ssd0 <="0100000";  -- '6'
            when "0111"=> ssd0 <="0001111";  -- '7'
            when "1000"=> ssd0 <="0000000";  -- '8'
            when "1001"=> ssd0 <="0000100";  -- '9'
				    when "1010"=> ssd0 <="0001000";  -- 'A'
				    when "1011"=> ssd0 <="1100000";  -- 'B'
				    when "1100"=> ssd0 <="0110001";  -- 'C'
				    when "1101"=> ssd0 <="1000010";  -- 'D'
				    when "1110"=> ssd0 <="0110000";  -- 'E'
				    when "1111"=> ssd0 <="0111000";  -- 'F'
            --nothing is displayed when a number more than 9 is given as input.
            when others=> ssd0 <="0000000";
				 end case; -- NUM1 case ends here
				
				
				case NUM2(3 downto 0) is
            when "0000"=> ssd1 <="0000001";  -- '0'
            when "0001"=> ssd1 <="1001111";  -- '1'
            when "0010"=> ssd1 <="0010010";  -- '2'
            when "0011"=> ssd1 <="0000110";  -- '3'
            when "0100"=> ssd1 <="1001100";  -- '4'
            when "0101"=> ssd1 <="0100100";  -- '5'
            when "0110"=> ssd1 <="0100000";  -- '6'
            when "0111"=> ssd1 <="0001111";  -- '7'
            when "1000"=> ssd1 <="0000000";  -- '8'
            when "1001"=> ssd1 <="0000100";  -- '9'
				    when "1010"=> ssd1 <="0001000";  -- 'A'
				    when "1011"=> ssd1 <="1100000";  -- 'B'
				    when "1100"=> ssd1 <="0110001";  -- 'C'
				    when "1101"=> ssd1 <="1000010";  -- 'D'
				    when "1110"=> ssd1 <="0110000";  -- 'E'
				    when "1111"=> ssd1 <="0111000";  -- 'F'
            --nothing is displayed when a number more than 9 is given as input.
            when others=> ssd1 <="0000000";
        end case; -- NUM2 case ends here
				
				
				case SUM(3 downto 0) is
            when "0000"=> ssd2 <="0000001";  -- '0'
            when "0001"=> ssd2 <="1001111";  -- '1'
            when "0010"=> ssd2 <="0010010";  -- '2'
            when "0011"=> ssd2 <="0000110";  -- '3'
            when "0100"=> ssd2 <="1001100";  -- '4'
            when "0101"=> ssd2 <="0100100";  -- '5'
            when "0110"=> ssd2 <="0100000";  -- '6'
            when "0111"=> ssd2 <="0001111";  -- '7'
            when "1000"=> ssd2 <="0000000";  -- '8'
            when "1001"=> ssd2 <="0000100";  -- '9'
				    when "1010"=> ssd2 <="0001000";  -- 'A'
				    when "1011"=> ssd2 <="1100000";  -- 'B'
				    when "1100"=> ssd2 <="0110001";  -- 'C'
				    when "1101"=> ssd2 <="1000010";  -- 'D'
				    when "1110"=> ssd2 <="0110000";  -- 'E'
				    when "1111"=> ssd2 <="0111000";  -- 'F'
            --nothing is displayed when a number more than 9 is given as input.
            when others=> ssd2 <="0000000";
        end case; -- NUM2 case ends here
				
				case SUM(4 downto 4) is
				    when "0"=> ssd3 <="0000001"; -- displays 0
				    when "1"=> ssd3 <="1001111"; -- displays 1
				    when others=> ssd3 <="1111111"; -- turn off unused ssd -- this should never occur in this lab
				end case;
        
		  end if;
    end process;
	 
end Behavioral;
