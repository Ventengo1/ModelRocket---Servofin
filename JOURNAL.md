---
title: "Your Project Name"
author: "Ventengo"
description: "A custom built model rocket with servo controlled fins to bring it back safely. (Similar to space shuttle)"
created_at: "2025-05-21"
---

# May 21st: Brainstorming and Finding Parts

- Brainstormed different ideas on what I could make
- Decieded on something model rocket related but searched the web for help
- Eventually came up with my own idea:
- Model rocket with a build in payload, altimeter, and 2 servo controlled fins so I could guide it back similar to a plane
- The idea for this came from the Space Shuttle

- Then worked on finding parts
- Eventually settled on the ESP32 board which has wifi control
- Allows me to control it from a different device
- Then decided on 2 Adafruit Servos to use for the fins
- Next Steps:
- Starting to create the body of the rocket

**Total time spent: 1.5h**

# May 22nd: Brainstorming and Finding Parts

- Created the nose cone, fuselage with a launch lug, and my nose cone coupler
- Body of the rocket will be 8.5in
- Then I will attach nose cone to the coupler
- Then attach Nose cone to body of rocket
- Made sure that the body of the rocket has a big enough diameter so that the ESP32 board could fit

  ![Screenshot 2025-05-22 194748](https://github.com/user-attachments/assets/20f406ec-f161-494c-8828-dc291f708dfe)


- After this spent about 30min researching different engines to use
- After I sliced the 3 things I made, they alone ended up using about 60g of filament so the total weight of the rocket is going to be ~ 100g
- Decided to use engine with 5-6oz maximum lift weight
- Settled on the Estes C11-3 rocket engine
- Has 22.10 Newtons (4.9lbs) of thrsut
- 3 second time delay for ejection charge
- Max Lift Weight = 6oz (170g)
- Issue is though the engine diameter is 24mm
- So will make the engine mount 24mm to fit the engine perfectly

![image](https://github.com/user-attachments/assets/06e9891e-c0ac-43d3-ac9c-c8a449f9be0d)


**Total time spent: 1.5h**


# May 23rd: Working on Fin section of rocket and finalizing servos

- Worked on figuring out how servo would fit
- Realized that I would need the servo the be at a veritcal orientation
- And for it to be smaller
- Oringally was using this servo:https://www.aliexpress.us/item/3256808061785803.html?spm=a2g0o.productlist.main.11.51c08752aypQdM&algo_pvid=51e031bd-3c3f-4e6a-a8a3-cedbc3230a41&algo_exp_id=51e031bd-3c3f-4e6a-a8a3-cedbc3230a41-10&pdp_ext_f=%7B%22order%22%3A%221380%22%2C%22eval%22%3A%221%22%2C%22orig_sl_item_id%22%3A%221005008248100555%22%2C%22orig_item_id%22%3A%221005007442852333%22%7D&pdp_npi=4%40dis%21USD%214.35%211.97%21%21%2131.14%2114.14%21%402103277f17480478097133871edb30%2112000044371515279%21sea%21US%210%21ABX&curPageLogUid=WFO2d8nIymAD&utparam-url=scene%3Asearch%7Cquery_from%3A
- But now could use this one:https://www.adafruit.com/product/169
- Newer one is smaller and lighter which will help the rocket greatly
- Either way, added areas on my current design for the bottom part of the rocket
- ![Screenshot 2025-05-23 202328](https://github.com/user-attachments/assets/a4f7be9c-65ff-4fe3-a573-d07c2a7369b9)


**Total time spent: 1h**

# May 24th: Finishing 3D Model for Fin section of rocket
 - Finished up work on the fin section
 - Decided to add 2 fins as 4 would result in too many servos
 - One issue is that the servos get in the way of most of the launch ejection charge
 - Going to find a way around this by adding a tube
 - Also made my engine mount work for a 24mm rocket engine
 - Added 2 fins which aren't connected yet because they will be attached to the servo
 - ![Screenshot 2025-05-24 155420](https://github.com/user-attachments/assets/af3c577c-9ecb-4587-af62-ab2f16c04a18)
![Screenshot 2025-05-24 155356](https://github.com/user-attachments/assets/70320981-a7e5-4cbe-a83f-cd746c0451d1)

**Total time spent: 2h**

# May 24th: Writing Code
 - Wrote code to control the servos
 - Allows me to control them wirelessly from a seperate device like my phone
 - Spent around 30 min looking on web for inspiration
 - After wrote the code and looked at how other created something similar
 - Don't have the ESP32 board to test
 -   Everything is set up in Arduino though
 - Later today or tommorow will work on finding batteries and mapping out how I will put everything inside the rocket without letting in get burnt\
 - ![Screenshot 2025-05-24 170119](https://github.com/user-attachments/assets/c741dd0b-d763-4207-a8db-b18fe2854fb0)

**Total time spent: 1.5h**

# May 25th: Find Boards and Batteries
 - Was just finishing up plans and then realized it is super difficult to connect 2 servos to ESP32
 - Spent about 1 hour looking for solutions and then finally settled on using another board and using I2C
 - Then spent another 1 hour finding the perfect board and finally decided on PCA9685
 - Has 16 servo channels
 - Has I2C
 - And will work has my SG90 servo
 - Then I worked on finding both a 5v battery to work with the servo board
 - And then a 3-4v battery to work with ESP32
 - Biggets issue I'm facing right now is the weight of the batteries and the size of them
 - Changed the ESP32 board to this: https://www.amazon.com/HiLetgo-ESP-WROOM-32-Development-Microcontroller-Integrated/dp/B0718T232Z
 - Added A Servo Driver Board : https://www.amazon.com/HiLetgo-PCA9685-Channel-12-Bit-Arduino/dp/B01D1D0CX2/ref=pd_lpo_d_sccl_1/130-0566564-6355817?pd_rd_w=N0b7z&content-id=amzn1.sym.4c8c52db-06f8-4e42-8e56-912796f2ea6c&pf_rd_p=4c8c52db-06f8-4e42-8e56-912796f2ea6c&pf_rd_r=C68A94E6A65529XK7T6W&pd_rd_wg=2kaNS&pd_rd_r=edb42ae9-2e47-42e0-aa57-b1dbcc266658&pd_rd_i=B01D1D0CX2&psc=1
 - Going to use the 3.7v batteries I have at home and buy 3v to 5v converters from Aliexpress
 - :https://www.aliexpress.us/item/2251832713406135.html?spm=a2g0o.productlist.main.1.75d951HR51HR3l&algo_pvid=09677a68-37a7-471c-80d3-7dd8453e537c&algo_exp_id=09677a68-37a7-471c-80d3-7dd8453e537c-0&pdp_ext_f=%7B%22order%22%3A%22631%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis%21USD%212.49%210.99%21%21%212.49%210.99%21%402101efeb17482077025604089e4d3d%2165881276347%21sea%21US%216376028355%21ABX&curPageLogUid=FGIut17SjQxe&utparam-url=scene%3Asearch%7Cquery_from%3A

   **Total time spent: 5.5h**



