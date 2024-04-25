# WAR PLANE 
 War plane is a game developed by Huy Hoang in 2024. The game using C++ and SDL2 is used for big exercise

 ## Demo Game 

## Dowload
- Cách 1 : bản chạy được luôn : tải warplane.rar và giải nén từ [game](https://github.com/daohuyhoangggg/warplane/releases/tag/releases)
- Cách 2 : - bản chạy trên IDE hoặc textEditor : clone repo hoặc Code -> download zip </br> Nếu dùng Visual Studio thì có thể vào file sln và cài đặt SDL2 rồi Ctrl + F5 để chạy
## Game Description
In War Plane, players can control a plane and navigate to avoid threats such as bullets, enemy planes, etc. and can use bullets to destroy them. During the game, the plane can eat items to increase its strength, gain points, etc. Destroying an enemy plane will help the player get 10 points. Each turn the player will have 3 lives, the game ends when the player

![image](https://github.com/daohuyhoangggg/warplane/assets/160694735/09fb94c2-d664-4461-8cbf-ef9d12e3b3ff)

## Game function
War plane is a fun and challenging game that tests the player's reflexes. It's great for killing time or competing with friends.
## How to play game
1. Select "Play game"

![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/play.png?raw=true)

3. Left click to start playing
4. If you hold down the left mouse button or press the mouse, the plane will start to fly
   If you release the mouse, the plane will slowly fall. When you touch the water, you will lose one life
5. Press the left mouse button to shoot bullets. When you hit the target, you will gain 10 points, whereas when you collide with the target or get hit, you will lose one life.
6. Eat items to go further:

   
   ![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/sao.png?raw=true)
   
     Plus 10 points




   ![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/cuong%20hoa.png?raw=true)

   
     Enhance bullets


7. The game ends when you use up all 3 lives
   ![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/over.png?raw=true)
   
.Practice makes perfect. Keep playing to improve your score and beat your friends' scores

# Source
- Image files (img), fonts (text) in the game focus on design or get any on google
- Sound files: [pixabay.com](https://pixabay.com/vi/sound-effects/)  

# Source code
- folder img : contains images, backgrounds, characters,...
- mix folder: contains sounds, sound_game, explosion missions,...
- folder ttf: contains fonts
- main : contains main function
- - Init() function: initialize SDL, set video window, initialize fonts, sounds...
- - saveHighScore() function: saves the highest score.
- - function LoadHighScore() : prints the highest score.
- - function main() : contains logic to control game streaming such as:
- - - initialize components
      - create objects: main object, threat object,...
      - display processing
      - enter game state: position, direction, collision of opponents,...
      - show status
      - check and process the end of the game
      - clean up the program
- receiver: declare library and game parameters
- - common processing functions such as:
    - - displays menu
    - - LoadImage() function: loads images and processes them
    - - ApplySurface() function: draw image
    - - function CheckCollision() : check and touch
- BaseObject: general object class, includes common data for objects
- Object plan classes from BaseObject class:
- - MainObject : main character (player)
    
  ![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/plane_object.png?raw=true)
    
- - ThreatObject:  enemy aircraft
 
    ![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/threat1.png?raw=true)                        threat1 : Can shoot bullets

    ![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/threat2.png?raw=true)                        threat2 : move at a fast speed
    
- - BulletObject :  bullets, handles bullets for main and threat objects

    ![image](https://github.com/daohuyhoangggg/warplane/assets/160694735/2b84d533-858f-4468-ac91-00bcee0c6878)  :                  bullet of player 
    
    ![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/bullet_threat.png?raw=true) :                 bullet of threat object
    
- - ExplosionObject : handles explosions.

  ![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/exp.png?raw=true)
    
- - HeartObject : player's number of lives
 
  ![image](https://github.com/daohuyhoangggg/warplane/blob/master/war%20plane/img/traitim.png?raw=true)
    
- - SkillObject: items that players can collect during gameplay
- - TextObject : font settings


## Contact
23020666@vnu.edu.vn
