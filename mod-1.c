/*  
 *  mod-1.c − The simplest kernel module.
 */
#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
int init_module(void)
{
        printk(KERN_INFO "Hello world 1.\n");
        /* 
         * A non 0 return means init_module failed; module can't be loaded. 
         */
        return 0;
}
void cleanup_module(void)
{
        printk(KERN_INFO "Goodbye world 1.\n");
}

/*

iqbal@iqbal-F17 ~ $ make
make -C /lib/modules/4.10.0-35-generic/build M=/home/iqbal modules
make[1]: Entering directory '/usr/src/linux-headers-4.10.0-35-generic'
  Building modules, stage 2.
  MODPOST 1 modules
make[1]: Leaving directory '/usr/src/linux-headers-4.10.0-35-generic'
iqbal@iqbal-F17 ~ $ 

*/
/*

iqbal-F17 iqbal # dmesg
[    0.000000] Linux version 4.10.0-35-generic (buildd@lcy01-33) (gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.4) ) #39~16.04.1-Ubuntu SMP Wed Sep 13 09:02:42 UTC 2017 (Ubuntu 4.10.0-35.39~16.04.1-generic 4.10.17)
[    0.000000] Command line: BOOT_IMAGE=/boot/vmlinuz-4.10.0-35-generic root=UUID=1d7d0cb5-2fbb-4920-bb3b-3762314a325c ro quiet splash
[    0.000000] KERNEL supported cpus:
[    0.000000]   Intel GenuineIntel
[    0.000000]   AMD AuthenticAMD
[    0.000000]   Centaur CentaurHauls
[    0.000000] x86/fpu: Legacy x87 FPU detected.
[    0.000000] e820: BIOS-provided physical RAM map:
[    0.000000] BIOS-e820: [mem 0x0000000000000000-0x000000000009fbff] usable
[    0.000000] BIOS-e820: [mem 0x000000000009fc00-0x000000000009ffff] reserved
[    0.000000] BIOS-e820: [mem 0x00000000000f0000-0x00000000000fffff] reserved
[    0.000000] BIOS-e820: [mem 0x0000000000100000-0x000000005ffeffff] usable
[    0.000000] BIOS-e820: [mem 0x000000005fff0000-0x000000005fffffff] ACPI data
[    0.000000] BIOS-e820: [mem 0x00000000fec00000-0x00000000fec00fff] reserved
[    0.000000] BIOS-e820: [mem 0x00000000fee00000-0x00000000fee00fff] reserved
[    0.000000] BIOS-e820: [mem 0x00000000fffc0000-0x00000000ffffffff] reserved
[    0.000000] NX (Execute Disable) protection: active
[    0.000000] SMBIOS 2.5 present.
[    0.000000] DMI: innotek GmbH VirtualBox/VirtualBox, BIOS VirtualBox 12/01/2006
[    0.000000] Hypervisor detected: KVM
[    0.000000] e820: update [mem 0x00000000-0x00000fff] usable ==> reserved
[    0.000000] e820: remove [mem 0x000a0000-0x000fffff] usable
[    0.000000] AGP: No AGP bridge found
[    0.000000] e820: last_pfn = 0x5fff0 max_arch_pfn = 0x400000000
[    0.000000] MTRR default type: uncachable
[    0.000000] MTRR variable ranges disabled:
[    0.000000] MTRR: Disabled
[    0.000000] x86/PAT: MTRRs disabled, skipping PAT initialization too.
[    0.000000] x86/PAT: Configuration [0-7]: WB  WT  UC- UC  WB  WT  UC- UC  
[    0.000000] CPU MTRRs all blank - virtualized system.
[    0.000000] found SMP MP-table at [mem 0x0009fff0-0x0009ffff] mapped at [ffff8fee4009fff0]
[    0.000000] Scanning 1 areas for low memory corruption
[    0.000000] Base memory trampoline at [ffff8fee40099000] 99000 size 24576
[    0.000000] BRK [0x5bc28000, 0x5bc28fff] PGTABLE
[    0.000000] BRK [0x5bc29000, 0x5bc29fff] PGTABLE
[    0.000000] BRK [0x5bc2a000, 0x5bc2afff] PGTABLE
[    0.000000] BRK [0x5bc2b000, 0x5bc2bfff] PGTABLE
[    0.000000] BRK [0x5bc2c000, 0x5bc2cfff] PGTABLE
[    0.000000] BRK [0x5bc2d000, 0x5bc2dfff] PGTABLE
[    0.000000] RAMDISK: [mem 0x32b40000-0x35597fff]
[    0.000000] ACPI: Early table checksum verification disabled
[    0.000000] ACPI: RSDP 0x00000000000E0000 000024 (v02 VBOX  )
[    0.000000] ACPI: XSDT 0x000000005FFF0030 00003C (v01 VBOX   VBOXXSDT 00000001 ASL  00000061)
[    0.000000] ACPI: FACP 0x000000005FFF00F0 0000F4 (v04 VBOX   VBOXFACP 00000001 ASL  00000061)
[    0.000000] ACPI: DSDT 0x000000005FFF0470 0021FF (v02 VBOX   VBOXBIOS 00000002 INTL 20100528)
[    0.000000] ACPI: FACS 0x000000005FFF0200 000040
[    0.000000] ACPI: FACS 0x000000005FFF0200 000040
[    0.000000] ACPI: APIC 0x000000005FFF0240 000054 (v02 VBOX   VBOXAPIC 00000001 ASL  00000061)
[    0.000000] ACPI: SSDT 0x000000005FFF02A0 0001CC (v01 VBOX   VBOXCPUT 00000002 INTL 20100528)
[    0.000000] ACPI: Local APIC address 0xfee00000
[    0.000000] No NUMA configuration found
[    0.000000] Faking a node at [mem 0x0000000000000000-0x000000005ffeffff]
[    0.000000] NODE_DATA(0) allocated [mem 0x5ffc5000-0x5ffeffff]
[    0.000000] kvm-clock: Using msrs 4b564d01 and 4b564d00
[    0.000000] kvm-clock: cpu 0, msr 0:5ff45001, primary cpu clock
[    0.000000] kvm-clock: using sched offset of 6403720690 cycles
[    0.000000] clocksource: kvm-clock: mask: 0xffffffffffffffff max_cycles: 0x1cd42e4dffb, max_idle_ns: 881590591483 ns
[    0.000000] Zone ranges:
[    0.000000]   DMA      [mem 0x0000000000001000-0x0000000000ffffff]
[    0.000000]   DMA32    [mem 0x0000000001000000-0x000000005ffeffff]
[    0.000000]   Normal   empty
[    0.000000]   Device   empty
[    0.000000] Movable zone start for each node
[    0.000000] Early memory node ranges
[    0.000000]   node   0: [mem 0x0000000000001000-0x000000000009efff]
[    0.000000]   node   0: [mem 0x0000000000100000-0x000000005ffeffff]
[    0.000000] Initmem setup node 0 [mem 0x0000000000001000-0x000000005ffeffff]
[    0.000000] On node 0 totalpages: 393102
[    0.000000]   DMA zone: 64 pages used for memmap
[    0.000000]   DMA zone: 21 pages reserved
[    0.000000]   DMA zone: 3998 pages, LIFO batch:0
[    0.000000]   DMA32 zone: 6080 pages used for memmap
[    0.000000]   DMA32 zone: 389104 pages, LIFO batch:31
[    0.000000] ACPI: PM-Timer IO Port: 0x4008
[    0.000000] ACPI: Local APIC address 0xfee00000
[    0.000000] IOAPIC[0]: apic_id 1, version 32, address 0xfec00000, GSI 0-23
[    0.000000] ACPI: INT_SRC_OVR (bus 0 bus_irq 0 global_irq 2 dfl dfl)
[    0.000000] ACPI: INT_SRC_OVR (bus 0 bus_irq 9 global_irq 9 high level)
[    0.000000] ACPI: IRQ0 used by override.
[    0.000000] ACPI: IRQ9 used by override.
[    0.000000] Using ACPI (MADT) for SMP configuration information
[    0.000000] smpboot: Allowing 1 CPUs, 0 hotplug CPUs
[    0.000000] PM: Registered nosave memory: [mem 0x00000000-0x00000fff]
[    0.000000] PM: Registered nosave memory: [mem 0x0009f000-0x0009ffff]
[    0.000000] PM: Registered nosave memory: [mem 0x000a0000-0x000effff]
[    0.000000] PM: Registered nosave memory: [mem 0x000f0000-0x000fffff]
[    0.000000] e820: [mem 0x60000000-0xfebfffff] available for PCI devices
[    0.000000] Booting paravirtualized kernel on KVM
[    0.000000] clocksource: refined-jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 7645519600211568 ns
[    0.000000] setup_percpu: NR_CPUS:8192 nr_cpumask_bits:1 nr_cpu_ids:1 nr_node_ids:1
[    0.000000] percpu: Embedded 36 pages/cpu @ffff8fee9fc00000 s107992 r8192 d31272 u2097152
[    0.000000] pcpu-alloc: s107992 r8192 d31272 u2097152 alloc=1*2097152
[    0.000000] pcpu-alloc: [0] 0 
[    0.000000] PV qspinlock hash table entries: 256 (order: 0, 4096 bytes)
[    0.000000] Built 1 zonelists in Node order, mobility grouping on.  Total pages: 386937
[    0.000000] Policy zone: DMA32
[    0.000000] Kernel command line: BOOT_IMAGE=/boot/vmlinuz-4.10.0-35-generic root=UUID=1d7d0cb5-2fbb-4920-bb3b-3762314a325c ro quiet splash
[    0.000000] PID hash table entries: 4096 (order: 3, 32768 bytes)
[    0.000000] AGP: Checking aperture...
[    0.000000] AGP: No AGP bridge found
[    0.000000] Calgary: detecting Calgary via BIOS EBDA area
[    0.000000] Calgary: Unable to locate Rio Grande table in EBDA - bailing!
[    0.000000] Memory: 1482808K/1572408K available (9068K kernel code, 1667K rwdata, 3828K rodata, 2228K init, 2364K bss, 89600K reserved, 0K cma-reserved)
[    0.000000] SLUB: HWalign=64, Order=0-3, MinObjects=0, CPUs=1, Nodes=1
[    0.000000] Hierarchical RCU implementation.
[    0.000000] 	Build-time adjustment of leaf fanout to 64.
[    0.000000] 	RCU restricting CPUs from NR_CPUS=8192 to nr_cpu_ids=1.
[    0.000000] RCU: Adjusting geometry for rcu_fanout_leaf=64, nr_cpu_ids=1
[    0.000000] NR_IRQS:524544 nr_irqs:256 16
[    0.000000] Console: colour VGA+ 80x25
[    0.000000] console [tty0] enabled
[    0.000000] tsc: Detected 2611.882 MHz processor
[    0.126625] Calibrating delay loop (skipped) preset value.. 5223.76 BogoMIPS (lpj=10447528)
[    0.126628] pid_max: default: 32768 minimum: 301
[    0.126641] ACPI: Core revision 20160930
[    0.127776] ACPI: 2 ACPI AML tables successfully acquired and loaded
[    0.127805] Security Framework initialized
[    0.127807] Yama: becoming mindful.
[    0.127820] AppArmor: AppArmor initialized
[    0.146747] Dentry cache hash table entries: 262144 (order: 9, 2097152 bytes)
[    0.147315] Inode-cache hash table entries: 131072 (order: 8, 1048576 bytes)
[    0.147644] Mount-cache hash table entries: 4096 (order: 3, 32768 bytes)
[    0.147647] Mountpoint-cache hash table entries: 4096 (order: 3, 32768 bytes)
[    0.147973] mce: CPU supports 0 MCE banks
[    0.147989] process: using AMD E400 aware idle routine
[    0.147995] Last level iTLB entries: 4KB 512, 2MB 16, 4MB 8
[    0.147995] Last level dTLB entries: 4KB 512, 2MB 128, 4MB 64, 1GB 0
[    0.153700] Freeing SMP alternatives memory: 32K
[    0.154714] ftrace: allocating 34225 entries in 134 pages
[    0.191821] smpboot: Max logical packages: 1
[    0.192221] x2apic enabled
[    0.192529] Switched APIC routing to physical x2apic.
[    0.193932] ..TIMER: vector=0x30 apic1=0 pin1=2 apic2=-1 pin2=-1
[    0.283390] APIC calibration not consistent with PM-Timer: 104ms instead of 100ms
[    0.283391] APIC delta adjusted to PM-Timer: 6483478 (6783858)
[    0.283474] smpboot: CPU0: AMD Phenom(tm) II X4 810 Processor (family: 0x10, model: 0x4, stepping: 0x2)
[    0.283556] Performance Events: PMU not available due to virtualization, using software events only.
[    0.283612] KVM setup paravirtual spinlock
[    0.284313] smp: Bringing up secondary CPUs ...
[    0.284315] smp: Brought up 1 node, 1 CPU
[    0.284317] smpboot: Total of 1 processors activated (5223.76 BogoMIPS)
[    0.284698] devtmpfs: initialized
[    0.284762] x86/mm: Memory block size: 128MB
[    0.288312] evm: security.selinux
[    0.288313] evm: security.SMACK64
[    0.288313] evm: security.SMACK64EXEC
[    0.288314] evm: security.SMACK64TRANSMUTE
[    0.288314] evm: security.SMACK64MMAP
[    0.288315] evm: security.ima
[    0.288315] evm: security.capability
[    0.288414] clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 7645041785100000 ns
[    0.288419] futex hash table entries: 256 (order: 2, 16384 bytes)
[    0.288451] pinctrl core: initialized pinctrl subsystem
[    0.288588] RTC time:  9:29:13, date: 09/30/17
[    0.288706] NET: Registered protocol family 16
[    0.288905] cpuidle: using governor ladder
[    0.288906] cpuidle: using governor menu
[    0.288907] PCCT header not found.
[    0.289214] ACPI: bus type PCI registered
[    0.289215] acpiphp: ACPI Hot Plug PCI Controller Driver version: 0.5
[    0.289318] PCI: Using configuration type 1 for base access
[    0.289318] PCI: Using configuration type 1 for extended access
[    0.290527] HugeTLB registered 2 MB page size, pre-allocated 0 pages
[    0.290733] ACPI: Added _OSI(Module Device)
[    0.290733] ACPI: Added _OSI(Processor Device)
[    0.290734] ACPI: Added _OSI(3.0 _SCP Extensions)
[    0.290735] ACPI: Added _OSI(Processor Aggregator Device)
[    0.291112] ACPI: Executed 1 blocks of module-level executable AML code
[    0.293503] ACPI: Interpreter enabled
[    0.293514] ACPI: (supports S0 S5)
[    0.293515] ACPI: Using IOAPIC for interrupt routing
[    0.293677] PCI: Using host bridge windows from ACPI; if necessary, use "pci=nocrs" and report a bug
[    0.297842] ACPI: PCI Root Bridge [PCI0] (domain 0000 [bus 00-ff])
[    0.297847] acpi PNP0A03:00: _OSC: OS supports [ExtendedConfig ASPM ClockPM Segments MSI]
[    0.297885] acpi PNP0A03:00: _OSC: OS now controls [PCIeHotplug PME AER PCIeCapability]
[    0.298253] PCI host bridge to bus 0000:00
[    0.298256] pci_bus 0000:00: root bus resource [io  0x0000-0x0cf7 window]
[    0.298257] pci_bus 0000:00: root bus resource [io  0x0d00-0xffff window]
[    0.298259] pci_bus 0000:00: root bus resource [mem 0x000a0000-0x000bffff window]
[    0.298260] pci_bus 0000:00: root bus resource [mem 0x60000000-0xffdfffff window]
[    0.298262] pci_bus 0000:00: root bus resource [bus 00-ff]
[    0.298317] pci 0000:00:00.0: [8086:1237] type 00 class 0x060000
[    0.299254] pci 0000:00:01.0: [8086:7000] type 00 class 0x060100
[    0.300293] pci 0000:00:01.1: [8086:7111] type 00 class 0x01018a
[    0.300869] pci 0000:00:01.1: reg 0x20: [io  0xd000-0xd00f]
[    0.301099] pci 0000:00:01.1: legacy IDE quirk: reg 0x10: [io  0x01f0-0x01f7]
[    0.301100] pci 0000:00:01.1: legacy IDE quirk: reg 0x14: [io  0x03f6]
[    0.301101] pci 0000:00:01.1: legacy IDE quirk: reg 0x18: [io  0x0170-0x0177]
[    0.301102] pci 0000:00:01.1: legacy IDE quirk: reg 0x1c: [io  0x0376]
[    0.301384] pci 0000:00:02.0: [80ee:beef] type 00 class 0x030000
[    0.303617] pci 0000:00:02.0: reg 0x10: [mem 0xe0000000-0xe0ffffff pref]
[    0.318692] pci 0000:00:03.0: [8086:100e] type 00 class 0x020000
[    0.320741] pci 0000:00:03.0: reg 0x10: [mem 0xf0000000-0xf001ffff]
[    0.324723] pci 0000:00:03.0: reg 0x18: [io  0xd010-0xd017]
[    0.333417] pci 0000:00:04.0: [80ee:cafe] type 00 class 0x088000
[    0.335520] pci 0000:00:04.0: reg 0x10: [io  0xd020-0xd03f]
[    0.337533] pci 0000:00:04.0: reg 0x14: [mem 0xf0400000-0xf07fffff]
[    0.339608] pci 0000:00:04.0: reg 0x18: [mem 0xf0800000-0xf0803fff pref]
[    0.348028] pci 0000:00:05.0: [8086:2415] type 00 class 0x040100
[    0.348167] pci 0000:00:05.0: reg 0x10: [io  0xd100-0xd1ff]
[    0.348265] pci 0000:00:05.0: reg 0x14: [io  0xd200-0xd23f]
[    0.349062] pci 0000:00:06.0: [106b:003f] type 00 class 0x0c0310
[    0.351560] pci 0000:00:06.0: reg 0x10: [mem 0xf0804000-0xf0804fff]
[    0.363992] pci 0000:00:07.0: [8086:7113] type 00 class 0x068000
[    0.364687] pci 0000:00:07.0: quirk: [io  0x4000-0x403f] claimed by PIIX4 ACPI
[    0.364701] pci 0000:00:07.0: quirk: [io  0x4100-0x410f] claimed by PIIX4 SMB
[    0.365065] pci 0000:00:0b.0: [8086:265c] type 00 class 0x0c0320
[    0.367298] pci 0000:00:0b.0: reg 0x10: [mem 0xf0805000-0xf0805fff]
[    0.379842] pci 0000:00:0d.0: [8086:2829] type 00 class 0x010601
[    0.381889] pci 0000:00:0d.0: reg 0x10: [io  0xd240-0xd247]
[    0.386177] pci 0000:00:0d.0: reg 0x18: [io  0xd250-0xd257]
[    0.390219] pci 0000:00:0d.0: reg 0x20: [io  0xd260-0xd26f]
[    0.392292] pci 0000:00:0d.0: reg 0x24: [mem 0xf0806000-0xf0807fff]
[    0.396075] ACPI: PCI Interrupt Link [LNKA] (IRQs 5 9 10 *11)
[    0.396317] ACPI: PCI Interrupt Link [LNKB] (IRQs 5 9 10 *11)
[    0.396424] ACPI: PCI Interrupt Link [LNKC] (IRQs 5 9 *10 11)
[    0.396529] ACPI: PCI Interrupt Link [LNKD] (IRQs 5 *9 10 11)
[    0.396706] ACPI: Enabled 2 GPEs in block 00 to 07
[    0.417387] SCSI subsystem initialized
[    0.417446] libata version 3.00 loaded.
[    0.417541] pci 0000:00:02.0: vgaarb: setting as boot VGA device
[    0.417543] pci 0000:00:02.0: vgaarb: VGA device added: decodes=io+mem,owns=io+mem,locks=none
[    0.417547] pci 0000:00:02.0: vgaarb: bridge control possible
[    0.417547] vgaarb: loaded
[    0.417570] ACPI: bus type USB registered
[    0.417586] usbcore: registered new interface driver usbfs
[    0.417597] usbcore: registered new interface driver hub
[    0.417606] usbcore: registered new device driver usb
[    0.417703] PCI: Using ACPI for IRQ routing
[    0.417705] PCI: pci_cache_line_size set to 64 bytes
[    0.417990] e820: reserve RAM buffer [mem 0x0009fc00-0x0009ffff]
[    0.417992] e820: reserve RAM buffer [mem 0x5fff0000-0x5fffffff]
[    0.418115] NetLabel: Initializing
[    0.418116] NetLabel:  domain hash size = 128
[    0.418116] NetLabel:  protocols = UNLABELED CIPSOv4 CALIPSO
[    0.418131] NetLabel:  unlabeled traffic allowed by default
[    0.418222] clocksource: Switched to clocksource kvm-clock
[    0.488413] VFS: Disk quotas dquot_6.6.0
[    0.488434] VFS: Dquot-cache hash table entries: 512 (order 0, 4096 bytes)
[    0.488533] AppArmor: AppArmor Filesystem Enabled
[    0.488585] pnp: PnP ACPI init
[    0.488668] pnp 00:00: Plug and Play ACPI device, IDs PNP0303 (active)
[    0.488767] pnp 00:01: Plug and Play ACPI device, IDs PNP0f03 (active)
[    0.489760] pnp: PnP ACPI: found 2 devices
[    0.495837] clocksource: acpi_pm: mask: 0xffffff max_cycles: 0xffffff, max_idle_ns: 2085701024 ns
[    0.495851] pci_bus 0000:00: resource 4 [io  0x0000-0x0cf7 window]
[    0.495853] pci_bus 0000:00: resource 5 [io  0x0d00-0xffff window]
[    0.495854] pci_bus 0000:00: resource 6 [mem 0x000a0000-0x000bffff window]
[    0.495856] pci_bus 0000:00: resource 7 [mem 0x60000000-0xffdfffff window]
[    0.495901] NET: Registered protocol family 2
[    0.496081] TCP established hash table entries: 16384 (order: 5, 131072 bytes)
[    0.496133] TCP bind hash table entries: 16384 (order: 6, 262144 bytes)
[    0.496261] TCP: Hash tables configured (established 16384 bind 16384)
[    0.496304] UDP hash table entries: 1024 (order: 3, 32768 bytes)
[    0.496319] UDP-Lite hash table entries: 1024 (order: 3, 32768 bytes)
[    0.496367] NET: Registered protocol family 1
[    0.496378] pci 0000:00:00.0: Limiting direct PCI/PCI transfers
[    0.496418] pci 0000:00:01.0: Activating ISA DMA hang workarounds
[    0.496488] pci 0000:00:02.0: Video device with shadowed ROM at [mem 0x000c0000-0x000dffff]
[    0.498867] PCI: CLS 0 bytes, default 64
[    0.498919] Unpacking initramfs...
[    2.394704] Freeing initrd memory: 43360K
[    2.395133] platform rtc_cmos: registered platform RTC device (no PNP device found)
[    2.395161] Scanning for low memory corruption every 60 seconds
[    2.395437] audit: initializing netlink subsys (disabled)
[    2.395811] Initialise system trusted keyrings
[    2.395836] audit: type=2000 audit(1506763764.110:1): initialized
[    2.395872] workingset: timestamp_bits=36 max_order=19 bucket_order=0
[    2.397471] zbud: loaded
[    2.397939] squashfs: version 4.0 (2009/01/31) Phillip Lougher
[    2.398128] fuse init (API version 7.26)
[    2.399148] Key type asymmetric registered
[    2.399150] Asymmetric key parser 'x509' registered
[    2.399191] Block layer SCSI generic (bsg) driver version 0.4 loaded (major 248)
[    2.399213] io scheduler noop registered
[    2.399214] io scheduler deadline registered
[    2.399222] io scheduler cfq registered (default)
[    2.399529] ACPI: AC Adapter [AC] (on-line)
[    2.399583] input: Power Button as /devices/LNXSYSTM:00/LNXPWRBN:00/input/input0
[    2.399586] ACPI: Power Button [PWRF]
[    2.399694] input: Sleep Button as /devices/LNXSYSTM:00/LNXSLPBN:00/input/input1
[    2.399696] ACPI: Sleep Button [SLPF]
[    2.399876] GHES: HEST is not enabled!
[    2.399985] Serial: 8250/16550 driver, 32 ports, IRQ sharing enabled
[    2.401276] Linux agpgart interface v0.103
[    2.402676] loop: module loaded
[    2.402783] ata_piix 0000:00:01.1: version 2.13
[    2.403371] scsi host0: ata_piix
[    2.403442] scsi host1: ata_piix
[    2.403475] ata1: PATA max UDMA/33 cmd 0x1f0 ctl 0x3f6 bmdma 0xd000 irq 14
[    2.403476] ata2: PATA max UDMA/33 cmd 0x170 ctl 0x376 bmdma 0xd008 irq 15
[    2.403547] libphy: Fixed MDIO Bus: probed
[    2.403548] tun: Universal TUN/TAP device driver, 1.6
[    2.403549] tun: (C) 1999-2004 Max Krasnyansky <maxk@qualcomm.com>
[    2.403997] PPP generic driver version 2.4.2
[    2.404041] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
[    2.404047] ehci-pci: EHCI PCI platform driver
[    2.404769] ehci-pci 0000:00:0b.0: EHCI Host Controller
[    2.404775] ehci-pci 0000:00:0b.0: new USB bus registered, assigned bus number 1
[    2.405041] ehci-pci 0000:00:0b.0: irq 19, io mem 0xf0805000
[    2.418996] ehci-pci 0000:00:0b.0: USB 2.0 started, EHCI 1.00
[    2.419047] usb usb1: New USB device found, idVendor=1d6b, idProduct=0002
[    2.419049] usb usb1: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    2.419050] usb usb1: Product: EHCI Host Controller
[    2.419051] usb usb1: Manufacturer: Linux 4.10.0-35-generic ehci_hcd
[    2.419052] usb usb1: SerialNumber: 0000:00:0b.0
[    2.419165] hub 1-0:1.0: USB hub found
[    2.419171] hub 1-0:1.0: 12 ports detected
[    2.419420] ehci-platform: EHCI generic platform driver
[    2.419429] ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
[    2.419431] ohci-pci: OHCI PCI platform driver
[    2.420046] ohci-pci 0000:00:06.0: OHCI PCI host controller
[    2.420051] ohci-pci 0000:00:06.0: new USB bus registered, assigned bus number 2
[    2.420121] ohci-pci 0000:00:06.0: irq 22, io mem 0xf0804000
[    2.480077] usb usb2: New USB device found, idVendor=1d6b, idProduct=0001
[    2.480079] usb usb2: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    2.480080] usb usb2: Product: OHCI PCI host controller
[    2.480081] usb usb2: Manufacturer: Linux 4.10.0-35-generic ohci_hcd
[    2.480082] usb usb2: SerialNumber: 0000:00:06.0
[    2.480190] hub 2-0:1.0: USB hub found
[    2.480205] hub 2-0:1.0: 12 ports detected
[    2.480645] ohci-platform: OHCI generic platform driver
[    2.480655] uhci_hcd: USB Universal Host Controller Interface driver
[    2.480709] i8042: PNP: PS/2 Controller [PNP0303:PS2K,PNP0f03:PS2M] at 0x60,0x64 irq 1,12
[    2.481221] serio: i8042 KBD port at 0x60,0x64 irq 1
[    2.481225] serio: i8042 AUX port at 0x60,0x64 irq 12
[    2.481332] mousedev: PS/2 mouse device common for all mice
[    2.481690] input: AT Translated Set 2 keyboard as /devices/platform/i8042/serio0/input/input2
[    2.482098] rtc_cmos rtc_cmos: rtc core: registered rtc_cmos as rtc0
[    2.482164] rtc_cmos rtc_cmos: alarms up to one day, 114 bytes nvram
[    2.482169] i2c /dev entries driver
[    2.482221] device-mapper: uevent: version 1.0.3
[    2.482282] device-mapper: ioctl: 4.35.0-ioctl (2016-06-23) initialised: dm-devel@redhat.com
[    2.482292] ledtrig-cpu: registered to indicate activity on CPUs
[    2.482620] NET: Registered protocol family 10
[    2.486521] Segment Routing with IPv6
[    2.486540] NET: Registered protocol family 17
[    2.486549] Key type dns_resolver registered
[    2.486749] registered taskstats version 1
[    2.486761] Loading compiled-in X.509 certificates
[    2.489584] Loaded X.509 cert 'Build time autogenerated kernel key: 3781ac46c2f7a743322097d3608bc638deea4293'
[    2.489601] zswap: loaded using pool lzo/zbud
[    2.506032] Key type big_key registered
[    2.506036] Key type trusted registered
[    2.507743] Key type encrypted registered
[    2.507745] AppArmor: AppArmor sha1 policy hashing enabled
[    2.507748] ima: No TPM chip found, activating TPM-bypass! (rc=-19)
[    2.507768] evm: HMAC attrs: 0x1
[    2.508176]   Magic number: 1:154:476
[    2.508278] rtc_cmos rtc_cmos: setting system clock to 2017-09-30 09:29:15 UTC (1506763755)
[    2.508356] BIOS EDD facility v0.16 2004-Jun-25, 0 devices found
[    2.508356] EDD information not available.
[    2.508381] PM: Hibernation image not present or could not be loaded.
[    2.564843] ata2.00: ATAPI: VBOX CD-ROM, 1.0, max UDMA/133
[    2.565220] ata2.00: configured for UDMA/33
[    2.565688] scsi 1:0:0:0: CD-ROM            VBOX     CD-ROM           1.0  PQ: 0 ANSI: 5
[    2.575601] sr 1:0:0:0: [sr0] scsi3-mmc drive: 32x/32x xa/form2 tray
[    2.575602] cdrom: Uniform CD-ROM driver Revision: 3.20
[    2.575726] sr 1:0:0:0: Attached scsi CD-ROM sr0
[    2.575936] sr 1:0:0:0: Attached scsi generic sg0 type 5
[    2.578380] Freeing unused kernel memory: 2228K
[    2.578381] Write protecting the kernel read-only data: 14336k
[    2.578957] Freeing unused kernel memory: 1156K
[    2.579784] Freeing unused kernel memory: 268K
[    2.588549] x86/mm: Checked W+X mappings: passed, no W+X pages found.
[    2.600603] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.600637] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.601174] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.601230] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.601245] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.601475] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.601552] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.601611] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.601668] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.601722] random: udevadm: uninitialized urandom read (16 bytes read)
[    2.658822] FUJITSU Extended Socket Network Device Driver - version 1.2 - Copyright (c) 2015 FUJITSU LIMITED
[    2.664300] ACPI: Video Device [GFX0] (multi-head: yes  rom: no  post: no)
[    2.664376] input: Video Bus as /devices/LNXSYSTM:00/LNXSYBUS:00/PNP0A03:00/LNXVIDEO:00/input/input4
[    2.675818] e1000: Intel(R) PRO/1000 Network Driver - version 7.3.21-k8-NAPI
[    2.675819] e1000: Copyright (c) 1999-2006 Intel Corporation.
[    2.952534] usb 2-1: new full-speed USB device number 2 using ohci-pci
[    2.992267] random: fast init done
[    2.992441] input: ImExPS/2 Generic Explorer Mouse as /devices/platform/i8042/serio1/input/input5
[    3.133016] e1000 0000:00:03.0 eth0: (PCI:33MHz:32-bit) 08:00:27:a2:3f:75
[    3.133022] e1000 0000:00:03.0 eth0: Intel(R) PRO/1000 Network Connection
[    3.133054] ahci 0000:00:0d.0: version 3.0
[    3.133692] ahci 0000:00:0d.0: SSS flag set, parallel bus scan disabled
[    3.133880] ahci 0000:00:0d.0: AHCI 0001.0100 32 slots 1 ports 3 Gbps 0x1 impl SATA mode
[    3.133883] ahci 0000:00:0d.0: flags: 64bit ncq stag only ccc 
[    3.135340] e1000 0000:00:03.0 enp0s3: renamed from eth0
[    3.136525] scsi host2: ahci
[    3.136603] ata3: SATA max UDMA/133 abar m8192@0xf0806000 port 0xf0806100 irq 21
[    3.275457] usb 2-1: New USB device found, idVendor=80ee, idProduct=0021
[    3.275459] usb 2-1: New USB device strings: Mfr=1, Product=3, SerialNumber=0
[    3.275461] usb 2-1: Product: USB Tablet
[    3.275462] usb 2-1: Manufacturer: VirtualBox
[    3.285746] hidraw: raw HID events driver (C) Jiri Kosina
[    3.302273] usbcore: registered new interface driver usbhid
[    3.302275] usbhid: USB HID core driver
[    3.309776] input: VirtualBox USB Tablet as /devices/pci0000:00/0000:00:06.0/usb2/2-1/2-1:1.0/0003:80EE:0021.0001/input/input6
[    3.310003] hid-generic 0003:80EE:0021.0001: input,hidraw0: USB HID v1.10 Mouse [VirtualBox USB Tablet] on usb-0000:00:06.0-1/input0
[    3.446851] ata3: SATA link up 3.0 Gbps (SStatus 123 SControl 300)
[    3.446976] ata3.00: ATA-6: VBOX HARDDISK, 1.0, max UDMA/133
[    3.446977] ata3.00: 41943040 sectors, multi 128: LBA48 NCQ (depth 31/32)
[    3.447076] ata3.00: configured for UDMA/133
[    3.447259] scsi 2:0:0:0: Direct-Access     ATA      VBOX HARDDISK    1.0  PQ: 0 ANSI: 5
[    3.447487] sd 2:0:0:0: [sda] 41943040 512-byte logical blocks: (21.5 GB/20.0 GiB)
[    3.447495] sd 2:0:0:0: [sda] Write Protect is off
[    3.447497] sd 2:0:0:0: [sda] Mode Sense: 00 3a 00 00
[    3.447510] sd 2:0:0:0: [sda] Write cache: enabled, read cache: enabled, doesn't support DPO or FUA
[    3.447725] sd 2:0:0:0: Attached scsi generic sg1 type 0
[    3.519341]  sda: sda1 sda2 < sda5 >
[    3.519719] sd 2:0:0:0: [sda] Attached SCSI disk
[    4.438502] tsc: Refined TSC clocksource calibration: 2611.795 MHz
[    4.438506] clocksource: tsc: mask: 0xffffffffffffffff max_cycles: 0x25a5c2a4d93, max_idle_ns: 440795304929 ns
[    5.877860] floppy0: no floppy controllers found
[    5.877918] work still pending
[    7.434367] raid6: sse2x1   gen()  3232 MB/s
[    7.483173] raid6: sse2x1   xor()  3547 MB/s
[    7.531110] raid6: sse2x2   gen()  5654 MB/s
[    7.578866] raid6: sse2x2   xor()  5630 MB/s
[    7.626738] raid6: sse2x4   gen()  6752 MB/s
[    7.674576] raid6: sse2x4   xor()  2938 MB/s
[    7.674578] raid6: using algorithm sse2x4 gen() 6752 MB/s
[    7.674578] raid6: .... xor() 2938 MB/s, rmw enabled
[    7.674580] raid6: using intx1 recovery algorithm
[    7.677400] xor: measuring software checksum speed
[    7.714644]    prefetch64-sse: 11847.000 MB/sec
[    7.754640]    generic_sse:  9280.000 MB/sec
[    7.754641] xor: using function: prefetch64-sse (11847.000 MB/sec)
[    7.778629] Btrfs loaded, crc32c=crc32c-generic
[    8.134617] EXT4-fs (sda1): mounted filesystem with ordered data mode. Opts: (null)
[    9.942733] random: crng init done
[   10.133134] systemd[1]: systemd 229 running in system mode. (+PAM +AUDIT +SELINUX +IMA +APPARMOR +SMACK +SYSVINIT +UTMP +LIBCRYPTSETUP +GCRYPT +GNUTLS +ACL +XZ -LZ4 +SECCOMP +BLKID +ELFUTILS +KMOD -IDN)
[   10.133180] systemd[1]: Detected virtualization oracle.
[   10.133184] systemd[1]: Detected architecture x86-64.
[   10.172305] systemd[1]: Set hostname to <iqbal-F17>.
[   13.119245] systemd[1]: Set up automount Arbitrary Executable File Formats File System Automount Point.
[   13.119289] systemd[1]: Reached target Encrypted Volumes.
[   13.119385] systemd[1]: Created slice User and Session Slice.
[   13.119395] systemd[1]: Reached target User and Group Name Lookups.
[   13.119429] systemd[1]: Listening on Device-mapper event daemon FIFOs.
[   13.119470] systemd[1]: Listening on Journal Socket (/dev/log).
[   14.916591] lp: driver loaded but no devices found
[   14.948498] ppdev: user-space parallel port driver
[   16.992307] EXT4-fs (sda1): re-mounted. Opts: errors=remount-ro
[   17.233395] systemd-journald[320]: Received request to flush runtime journal from PID 1
[   18.751967] vboxguest: loading out-of-tree module taints kernel.
[   18.752248] vboxguest: module verification failed: signature and/or required key missing - tainting kernel
[   18.756334] vgdrvHeartbeatInit: Setting up heartbeat to trigger every 2000 milliseconds
[   18.756440] input: Unspecified device as /devices/pci0000:00/0000:00:04.0/input/input7
[   18.758492] vboxguest: misc device minor 55, IRQ 20, I/O port d020, MMIO at 00000000f0400000 (size 0x400000)
[   18.758493] vboxguest: Successfully loaded version 5.1.28 (interface 0x00010004)
[   20.167668] piix4_smbus 0000:00:07.0: SMBus Host Controller at 0x4100, revision 0
[   20.329916] [drm] Initialized
[   21.490427] floppy0: no floppy controllers found
[   21.513996] [drm] VRAM 01000000
[   21.518368] [TTM] Zone  kernel: Available graphics memory: 764926 kiB
[   21.518369] [TTM] Initializing pool allocator
[   21.518373] [TTM] Initializing DMA pool allocator
[   21.518902] fbcon: vboxdrmfb (fb0) is primary device
[   21.541324] Console: switching to colour frame buffer device 100x37
[   21.548239] vboxvideo 0000:00:02.0: fb0: vboxdrmfb frame buffer device
[   21.548255] [drm] Initialized vboxvideo 1.0.0 20130823 for 0000:00:02.0 on minor 0
[   21.661458] EDAC MC: Ver: 3.0.0
[   21.987438] MCE: In-kernel MCE decoding enabled.
[   22.966610] snd_intel8x0 0000:00:05.0: white list rate for 1028:0177 is 48000
[   23.969842] Adding 3391484k swap on /dev/sda5.  Priority:-1 extents:1 across:3391484k FS
[   24.200887] audit: type=1400 audit(1506763777.188:2): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/usr/lib/lightdm/lightdm-guest-session" pid=633 comm="apparmor_parser"
[   24.200889] audit: type=1400 audit(1506763777.188:3): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/usr/lib/lightdm/lightdm-guest-session//chromium" pid=633 comm="apparmor_parser"
[   24.318128] audit: type=1400 audit(1506763777.304:4): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/sbin/dhclient" pid=634 comm="apparmor_parser"
[   24.318131] audit: type=1400 audit(1506763777.304:5): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/usr/lib/NetworkManager/nm-dhcp-client.action" pid=634 comm="apparmor_parser"
[   24.318132] audit: type=1400 audit(1506763777.304:6): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/usr/lib/NetworkManager/nm-dhcp-helper" pid=634 comm="apparmor_parser"
[   24.318133] audit: type=1400 audit(1506763777.304:7): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/usr/lib/connman/scripts/dhclient-script" pid=634 comm="apparmor_parser"
[   24.445070] audit: type=1400 audit(1506763777.432:8): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/usr/sbin/cups-browsed" pid=636 comm="apparmor_parser"
[   24.566209] audit: type=1400 audit(1506763777.552:9): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/usr/lib/cups/backend/cups-pdf" pid=637 comm="apparmor_parser"
[   24.566212] audit: type=1400 audit(1506763777.552:10): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/usr/sbin/cupsd" pid=637 comm="apparmor_parser"
[   24.566213] audit: type=1400 audit(1506763777.552:11): apparmor="STATUS" operation="profile_load" profile="unconfined" name="/usr/sbin/cupsd//third_party" pid=637 comm="apparmor_parser"
[   26.330611] cgroup: new mount options do not match the existing superblock, will be ignored
[   29.446271] vboxsf: Successfully loaded version 5.1.28 (interface 0x00010004)
[   38.541417] VBoxService 5.1.28 r117968 (verbosity: 0) linux.amd64 (Sep 13 2017 11:07:52) release log
               00:00:00.000124 main     Log opened 2017-09-30T09:29:51.533060000Z
[   38.541951] 00:00:00.000682 main     OS Product: Linux
[   38.542207] 00:00:00.000945 main     OS Release: 4.10.0-35-generic
[   38.542500] 00:00:00.001234 main     OS Version: #39~16.04.1-Ubuntu SMP Wed Sep 13 09:02:42 UTC 2017
[   38.542745] 00:00:00.001476 main     Executable: /opt/VBoxGuestAdditions-5.1.28/sbin/VBoxService
               00:00:00.001478 main     Process ID: 924
               00:00:00.001479 main     Package type: LINUX_64BITS_GENERIC
[   38.544167] 00:00:00.002908 main     5.1.28 r117968 started. Verbose level = 0
[   42.878509] IPv6: ADDRCONF(NETDEV_UP): enp0s3: link is not ready
[   42.880682] IPv6: ADDRCONF(NETDEV_UP): enp0s3: link is not ready
[   42.884975] e1000: enp0s3 NIC Link is Up 1000 Mbps Full Duplex, Flow Control: RX
[   42.885325] IPv6: ADDRCONF(NETDEV_CHANGE): enp0s3: link becomes ready
[  330.414667] mod_1: version magic '4.10.0-33-generic SMP mod_unload ' should be '4.10.0-35-generic SMP mod_unload '
[  380.275684] mod_1: version magic '4.10.0-33-generic SMP mod_unload ' should be '4.10.0-35-generic SMP mod_unload '
[  465.651978] mod_1: version magic '4.10.0-33-generic SMP mod_unload ' should be '4.10.0-35-generic SMP mod_unload '
[  660.404411] mod_1: module license 'unspecified' taints kernel.
[  660.404413] Disabling lock debugging due to kernel taint
[  660.406214] Module Mod-1 added... 
iqbal-F17 iqbal # 

*/