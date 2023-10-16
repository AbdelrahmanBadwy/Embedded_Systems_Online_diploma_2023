/*linker_script_cortexM4
Eng.Abdelrahman_ElBadawy
*/

MEMORY
{
flash(RX) : ORIGIN = 0X00000000, LENGTH = 512M
sram(RWX) : ORIGIN = 0X20000000, LENGTH = 512M

}


SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_text = . ;
	} > flash

	.data : {
		_S_Data = . ;
		*(.data*)
		. = ALIGN(4) ;
		_E_Data = . ;
	} > sram AT> flash

	.bss : {
		_S_Bss = . ;
		*(.bss*)
		_E_Bss = . ;
	} > sram
}