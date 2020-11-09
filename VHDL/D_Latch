-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- PROGRAM		"Quartus II 64-Bit"
-- VERSION		"Version 13.0.1 Build 232 06/12/2013 Service Pack 1 SJ Web Edition"
-- CREATED		"Mon Nov 09 16:47:13 2020"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY D_Latch IS 
	PORT
	(
		Gate :  IN  STD_LOGIC;
		Data :  IN  STD_LOGIC;
		Q :  OUT  STD_LOGIC;
		Qnot :  OUT  STD_LOGIC
	);
END D_Latch;

ARCHITECTURE bdf_type OF D_Latch IS 

COMPONENT sr_latch
	PORT(S : IN STD_LOGIC;
		 R : IN STD_LOGIC;
		 Qnot : OUT STD_LOGIC;
		 Q : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;


BEGIN 



b2v_inst : sr_latch
PORT MAP(S => SYNTHESIZED_WIRE_0,
		 R => SYNTHESIZED_WIRE_1,
		 Qnot => Qnot,
		 Q => Q);


SYNTHESIZED_WIRE_0 <= Data AND Gate;


SYNTHESIZED_WIRE_1 <= Gate AND SYNTHESIZED_WIRE_2;


SYNTHESIZED_WIRE_2 <= NOT(Data);



END bdf_type;
