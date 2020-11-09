-- inspired by: 
-- https://electronics.stackexchange.com/questions/454634/seven-segment-display-vhdl-code-issue
-- Xuhua Huang 1879700
-----------------------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL; 

entity decoder is
port(
    clk  : in  std_logic;
	 
    bcd  : in  std_logic_vector(3 downto 0);   -- BCD input
    ssd  : out std_logic_vector(6 downto 0)    -- 7 bit decoded output.
    );
end decoder;

architecture Behavioral of decoder is

begin

    BCD_process : process (clk)
    begin
        if rising_edge(clk) then
            case  bcd is
            when "0000"=> ssd <="0000001";  -- '0'
            when "0001"=> ssd <="1001111";  -- '1'
            when "0010"=> ssd <="0010010";  -- '2'
            when "0011"=> ssd <="0000110";  -- '3'
            when "0100"=> ssd <="1001100";  -- '4'
            when "0101"=> ssd <="0100100";  -- '5'
            when "0110"=> ssd <="0100000";  -- '6'
            when "0111"=> ssd <="0001111";  -- '7'
            when "1000"=> ssd <="0000000";  -- '8'
            when "1001"=> ssd <="0000100";  -- '9'
				
				    when "1010"=> ssd <="0001000";  -- 'A'
				    when "1011"=> ssd <="1100000";  -- 'B'
				    when "1100"=> ssd <="0110001";  -- 'C'
				    when "1101"=> ssd <="1000010";  -- 'D'
				    when "1110"=> ssd <="0110000";  -- 'E'
				    when "1111"=> ssd <="0111000";  -- 'F'

            --nothing is displayed when a number more than 9 is given as input.
            when others=> ssd <="0000000";
            end case;
				
        end if;
    end process;
end architecture;
