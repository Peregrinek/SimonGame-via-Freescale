# SimonGame-via-Freescale
## Background
> Simon was an electronic game introduced in 1978 as shown in the picture below, it was one of the top selling Christmas toys in the US that year. The device creates a sequence using the colour lights, the player has to respond by pressing the colour lights in the same order. The sequence gets longer through each iteration, with the game ending when the user enters an incorrect sequence.
## Introduction
> This project is developed based on Freescale FRDM-KL05Z. It's not perfect, just for reference (if you happen to discover it).
## Game explanation
>1. The game starts with a breathing light for a few seconds.
>2. When the breathing light ends you can touch the touch pad to start the game while the system starts seeding for the first random number generation.
>3. When the white light is on, the game starts. You need to press the different positions of the touch pad according to the colour of the flashing lights.
>>* The left side is the red light
>>* In the middle is the green light
>>* Right is the blue light
>4. When you have finished judging and pressing the touch pad, the system starts to generate random seeds for the next round of new positions.
>5. If you complete a round successfully, the magenta light will flash once.
>6. If you are lucky enough to complete 50 rounds successfully or if you are unlucky enough to fail, you will get a breathing light that changes colour infinitely.
