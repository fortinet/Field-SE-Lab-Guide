+++
title = "How-To Build Enclosure"
type = "default"
weight = 30
+++

### **Enclosure Build Steps**
**Enclosure Prep**
![Case_01](Case_01.png)

**Remove Lid**
![Case_02](Case_02.png)

**Remove Pick-and-Pull Foam Insert**
![Case_03](Case_03.png)

### **Mount DIN Rails**
**Remove Back of Enclosure**
![Case_04](Case_04.png)

**Cut DIN Rails to length**
- Use 1/8” drill bit to make 4 evenly spaced holes for bolts
- Secure with M4x16 bolts
- Drill holes from Inside case

- Bottom DIN rail (Power Supply Rail) needs to be "just below" nubs as seen below
![Case_05a](Case_05a.png)

- Middle DIN rail (FGR/FSR Rail) needs to be "just above" nubs as seen below
![Case_05b](Case_05b.png)

- Top DIN rail (Modbus/Digital I/O Rail) needs to be "just below" nubs as seen below
![Case_06](Case_06.png)

**Backside View**
- Use 5/16" drill bit BY HAND (don't use drill) to create countersink
![Case_06a](Case_06a.png)

![Case_06b](Case_06b.png)

- Put flat washer and nut on each bolt (except the end one) and tighten
![Case_07](Case_07.png)

- Create Ground Wire daisy chain between each rail as show below
- The last rail will be connected to Ground Terminal Block (it will use ferrule connector)
![Case_07a](Case_07a.png)

### **Wall Power Adapter**
**Make Hole to Fit Adapter**
- Use Hole Template
![Case_08a](Case_08a.jpg)

- Create Hole
![Case_08b](Case_08b.jpg)

- Fit Power Plug into Hole 
![Case_08b](Case_08c.jpg)

### **Wiring Topology**
![Wiring_Topology](Wiring_Topology.png)

### **Wiring Wall Power Adapter**
- Solder Wires to 3-Prong Adapter
- Use standard colors for US single-phase AC:
   - Line/Black
   - Neutral/White
   - Earth-Ground/Green
- Use shrink tubing to cover soldered connections
- Cut wires to length for inserting/affixing to DIN Rail Terminal Blocks 
![Power_Plug_Back](Power_Plug_Back.jpg)

![Case_08d](Case_08d.jpg)

### **Wiring Wall Power Adapter to AC Terminal Blocks**
- Picture below shows 2 each of terminal blocks (appropriate for 2 Power Supplies)
- **Note:** Jumper used to connect the two terminal blocks
![Case_09a](Case_09a.jpg)

- Picture below shows 3 each of terminal blocks (appropriate for 3 Power Supplies)
- **Note:** Two Jumpers used to connect the three terminal blocks
![Case_13a](Case_13a.jpg)

### **Wiring AC Terminal Blocks to DC Power Supplies**
- Use standard colors for US single-phase AC:
   - Line/Black
   - Neutral/White
   - Earth-Ground/Green
- **Note:** Three Power Supplies shown below, Left most is the 12VDC Power Supply [listed in the Digital I/O BOM](Extras/OT_Demo_Lab/Bill_of_Materials/#digital-io-components), the two right most are the Fortinet Rugged Power Supplies
![Case_14a](Case_14a.jpg)

![Case_15](Case_15.png)

### **Wiring DC Power Supplies to DC Terminal Blocks**
- Suggested 48VDC colors:
   - V+ == Blue
   - V- == White
- If using dual power supplies, do this step twice (once for each Power Supply)
![Case_16a](Case_16a.jpg)

![Case_16b](Case_16b.jpg)

### **Mount and Wire = FGR and FSR**

![Case_17](Case_17.jpg)

![Case_18](Case_18.jpg)

### **Finished**

![Case_19](Case_19.png)

![Case_20](Case_20.png)

![Case_21](Case_21.png)
