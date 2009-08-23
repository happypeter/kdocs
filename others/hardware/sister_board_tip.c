Sister board:
1. yesterday, I felt bad about that
   the core board failed to find the kernel after recover_system.
   I do not understand why kenel was found when booting from nfs,
   while lost later.(using the new core board with its original vivi)
2. today, it suddenly comes to me that maybe the vivi is different,
   maybe it is for yaffs system(the old core board is using yaffs now),
   so I change it into the yctek vivi, then everything comes right.
3. since I do not have screen for now,
   so I delete th qt tar package,
   and the result is the failure of finding busybox.
   I put qt back to /yctek/root,
   #recover_system
   #reboot
   this time I am still not be able to use busybox,
   because of the lack of pointercal file.
   But that is easy for me,
   all I need to do is add “cp qt/pointercal /etc” to rcS.
4. so finally, everything is a OK,
   but one question remains:
   how can the yaffs vivi find my newly installed kernel during nfs booting.
5. In sister board all common resistor symbol is
   –口--
  （in yctek sch file, they use –w—mostly）,
   I will use –口—
6. that happens to electro capacitor too.
   I perfer –口 |--（yctek use -| (-)
  
7. yctek connect AIN4,6(R15,16 of 2410),
   to the 34-pin connector(not used),
   while sister does not connect them at all,
   so I can do it either way, even when I try to use ts.
8. in my sisiter core board OM1 in connected to GND,
   while OM0 is determined by the JumpWire.
 
9. the way how you orgnize your lib conponents is very important.
   I will put common component symbols and footprint in ALL_sch.lib and ALL_pcb.lib.
   the ones used only in jtag part,
   I will put its symbol and footprint in /jtag/jtag_pcb.lib and jtag_sch.lib.

