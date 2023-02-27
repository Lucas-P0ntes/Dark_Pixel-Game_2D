#include "raylib.h"
#include <stdio.h>

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1024;
    

    InitWindow(screenWidth, screenHeight, "Dark_Pixel");
    
     SetTargetFPS(60);
     
     
       InitAudioDevice();

Music music = LoadMusicStream("./../audio/Beep2.MP3");
 PlayMusicStream(music);
 
 
 //firabollsong
 
 
 Sound firebollsong= LoadSound("./../audio/firabollsong.mp3");
  Sound hit_boneco= LoadSound("./../audio/hit_boneco.mp3");
//------------------------------------------------------------------------------------------   
    //Mapas do jogo
    
    Texture2D Background = LoadTexture("./../img/background2.png");
    int frameWidthBackground = Background.width/4;
    int frameHeightBackground = Background.height;
    int currentFrameBackground = 0; 
//--------------------------------------------------------------------------------------------------------
                    //ACESSETS
                    
                    
        //barra_life_boss
        
        Texture2D barra_life_boss= LoadTexture("./../img/barra_life_boss.png");
    int frameWidthbarra_life_boss= barra_life_boss.width/16;
    int frameHeightbarra_life_boss = barra_life_boss.height;
    int currentFramebarra_life_boss = 0; 

      //Barra life
    
    Texture2D Life= LoadTexture("./../img/Life.png");
    int frameWidthLife= Life.width/8;
    int frameHeightLife = Life.height;
    int currentFrameLife = 0; 
    
    //bollFire
    
    Texture2D fireboll= LoadTexture("./../img/bollFire.png");
    int frameWidthfireboll= fireboll.width/6;
    int frameHeightfireboll = fireboll.height;
    int frameCountfireboll= 6; 
    int currentFramefireboll = 0; 
    
    //florhit
     Texture2D florhit = LoadTexture("./../img/florhit.png");
    int frameWidthflorhit= florhit.width/3;
    int frameHeightflorhit = florhit.height;
    int frameCountflorhit= 3; 
    int currentFrameflorhit = 0; 

  //-------------------------------------------------------------------------------------------------
  
                //PESONAGENS
  
   // inseto
    
    Texture2D  Inseto= LoadTexture("./../img/inseto.png");
    int frameWidthInseto= Inseto.width/8;
    int frameHeightInseto = Inseto.height;
     int frameCountInseto = 3;
     int frameCountInsetoMorto=8;
    int currentFrameInseto = 0; 
    
    
       // boss
    
    Texture2D  Boss = LoadTexture("./../img/bossbig.png");
    int frameWidthBoss= Boss.width/7;
    int frameHeightBoss = Boss.height;
     int frameCountBoss = 7;
    int currentFrameBoss = 0; 

    
    // Personagem 
    
    Texture2D spritesheet = LoadTexture("./../img/mago.png");// Carrega uma lista de um personagem
    int frameWidth = spritesheet.width/14; // Divide em 4, ja que são 4 animações e aplica a uma 
    int frameHeight = spritesheet.height; // pega a altura 
    int frameCount = 4; // Fala ue são 4 itens 
    int frameCount2=9;
     int frameCount3=14;
    int currentFrame = 0; // Define o índice do quadro atual da animação.
    float frameTime = 0.08f;//Define a quantidade de tempo que cada quadro deve ser exibido em segundos.
    float elapsed = 0.0f;//Define a quantidade de tempo decorrido desde a exibição do último quadro.
    
    // -----------------------------------------------------------------------------------------------------
    
    float frameTime_hit = 1;
    float elapsed_hit = 0.0f;
    
    float elapsed_flor = 1;
    float frameTime_flor=0.05f;
 
    

    
    
    // ATRIBUTO DOS PERSONAGENS
  
    //cavaleiro
    typedef struct{ 
    int positionHeight ;
    int positionWidth ;
    int personSpeed ;
    int life ;
    Color color ;
        bool morto;
    }Person_game;
    
    //Monstro
     typedef struct{ 
    int positionHeight ;
    int positionWidth ;
    int personSpeed ;
    int life ;
    Color color ;
    bool morto;
    }mostro_game;
    
    //fireboll
    typedef struct{ 
    int positionHeight ;
    int positionWidth ;
    int bollSpeed ;
    int dano;
    Color color ;
    }projetio;
    
    
    //----------------------------------------------------------------------------------------
    
    //Criação dos personagens
    
    //Person Cavaleiro
    Person_game person;
    
    person.positionHeight = 745;
    person.positionWidth = 50;
    person.personSpeed = 10;
    person.color = WHITE;
    person.life=100;
    person.morto=false;
        
        
     //Mosntro
     mostro_game inseto;
     
     inseto.positionHeight = 740;
     inseto.positionWidth = 500;
     inseto.personSpeed = 10;
     inseto.color = WHITE;
     inseto.life=50;
     inseto.morto= false;
     
      //boss
     mostro_game boss;
     
     boss.positionHeight = 700;
     boss.positionWidth = 1500;
     boss.personSpeed = 10;
     boss.color = WHITE;
     boss.life=160;
     boss.morto= false;
     
     //fireboll
     projetio fireBoll;
     
     fireBoll.positionHeight = 740;
     fireBoll.positionWidth = person.positionWidth;
     fireBoll.bollSpeed = 15;
     fireBoll.color = WHITE;
     fireBoll.dano=100;
     
     //florhit
     
     projetio florHit;
     
       florHit.positionHeight = 800;
     florHit.positionWidth = boss.positionWidth;
     florHit.bollSpeed = 15;
     florHit.color = WHITE;
     florHit.dano=100;
     
    
    //---------------------------------------------------------------------------------------------------------------
    
    // Variaveis do game 
       
        
        int i =1 ;
    bool collision = false;
     bool atk_fireboll = false;
    
     bool   ataque_fireBoll =false;

        
       bool atk_fireboll_boss = false;
       
       bool    collision_boss= false;
       
       bool collision_flor = false;
       
       bool ataque_florhit = false;
        bool gravidade = true;
        
bool aviso = false ;
    
     //                                                      Inicio do LOOP
    //######################################################################################################################


do{
        
       UpdateMusicStream(music);
        
        
       
        
     
       // NAVEGAÇÂO NO MAPA 
   
            // Seguindo em frete
        
        if(person.positionWidth >= screenWidth-100){
          
             
            if(currentFrameBackground < 3){
                
                currentFrameBackground++;
                person.positionWidth = 50;
            }
            
        }
        
           // Voltando 
            
        if(person.positionWidth <= (-10)){ 
            if(currentFrameBackground >0){
                currentFrameBackground--;
                person.positionWidth = screenWidth-100;
                
            }
         
             
        }
            
            
       
    //-----------------------------------------------------------------------------------------------------------------------------
    
  
    // ANIMAÇÂO + MOVIMENTAÇÂO
    
    
    
        //ataque
         if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && person.morto==false){
             
              ataque_fireBoll = true;
              PlaySound(firebollsong);
 
         }
         
       if( fireBoll.positionWidth <=2020 && ataque_fireBoll == true && atk_fireboll == false && atk_fireboll_boss == false ){
      
          fireBoll.positionWidth  +=  fireBoll.bollSpeed;
          
              
          } 
          else {
          ataque_fireBoll = false;
          fireBoll.positionWidth  = person.positionWidth;
          }
          
         
    // pular 
    
    if(person.morto==false){

        
        
        
        if(IsKeyDown(KEY_W) && person.positionHeight >=600  ){
            
            person.positionHeight -=  person.personSpeed;
            
        } else if( gravidade== true &&  person.positionHeight<=745){
            
            person.positionHeight +=  person.personSpeed;
            
        
        }else{
            
            
        }
        
    }
    
     
    
    
    
    
         
        //Direita_person
      if(person.morto==false){
        if(IsKeyDown(KEY_D)){

            if(currentFrameBackground == 3 && person.positionWidth>=screenWidth-200 ){
             
             
            }else{
                person.positionWidth +=  person.personSpeed;
            }
            
            
            elapsed += GetFrameTime();//Adiciona o tempo decorrido desde o último frame ao tempo total decorrido.
            
            if (elapsed >= frameTime){//Verifica se tempo decorrido é maior ou igual ao tempo que o quadro atual deve ser exibido.
            
                currentFrame++;// Incrementa o índice do quadro atual.
                
                if (currentFrame>= frameCount){//Verifica se o índice do quadro atual ultrapassou o número total de quadros na animação. Se sim, volta ao primeiro quadro.
                    currentFrame = 0;
                }
                
               elapsed = 0.0f;
            }
        }
        
        
        //Esquerda_person
        if(IsKeyDown(KEY_A)){
            
            
            if(currentFrameBackground == 0 && person.positionWidth<=-10 ){
             
             
            }else{
                person.positionWidth-=   person.personSpeed;
            }
            
            elapsed += GetFrameTime();//Adiciona o tempo decorrido desde o último frame ao tempo total decorrido.
            
            
            if (elapsed >= frameTime){//Verifica se tempo decorrido é maior ou igual ao tempo que o quadro atual deve ser exibido.
            
                currentFrame++;// Incrementa o índice do quadro atual.
                
                if (currentFrame >= frameCount2){//Verifica se o índice do quadro atual ultrapassou o número total de quadros na animação. Se sim, volta ao primeiro quadro.
                    currentFrame = 7;
                }
                
                elapsed = 0.0f;
            }
             
        }
      }else{
          
          
             elapsed += GetFrameTime();//Adiciona o tempo decorrido desde o último frame ao tempo total decorrido.
            
            
            if (elapsed >= frameTime){//Verifica se tempo decorrido é maior ou igual ao tempo que o quadro atual deve ser exibido.
            
                currentFrame++;// Incrementa o índice do quadro atual.
                
                if (currentFrame >= frameCount3){//Verifica se o índice do quadro atual ultrapassou o número total de quadros na animação. Se sim, volta ao primeiro quadro.
                    currentFrame = 13;
                }
                
                elapsed = 0.0f;
            }
          
          
      }
      //---------------------------------------------------------------------------------------------------------------
        //MOVIMENTAÇÂO  DOS MONSTROS
      
      // Animeção inseto 
      
      if(currentFrameBackground == 1 && inseto.morto == false){
         elapsed += GetFrameTime();//Adiciona o tempo decorrido desde o último frame ao tempo total decorrido.
            
            if (elapsed >= frameTime){//Verifica se tempo decorrido é maior ou igual ao tempo que o quadro atual deve ser exibido.

                currentFrameInseto++;// Incrementa o índice do quadro atual.
                
                if (currentFrameInseto >= frameCountInseto ){//Verifica se o índice do quadro atual ultrapassou o número total de quadros na animação. Se sim, volta ao primeiro quadro.
                    currentFrameInseto= 0;
                }
                
                elapsed = 0.0f;
            }
      }else {
          
            elapsed += GetFrameTime();//Adiciona o tempo decorrido desde o último frame ao tempo total decorrido.
            
            if (elapsed >= frameTime){//Verifica se tempo decorrido é maior ou igual ao tempo que o quadro atual deve ser exibido.

                currentFrameInseto++;// Incrementa o índice do quadro atual.
                
                if (currentFrameInseto >= frameCountInsetoMorto ){//Verifica se o índice do quadro atual ultrapassou o número total de quadros na animação. Se sim, volta ao primeiro quadro.
                    currentFrameInseto= 6;
                }
                
                elapsed = 0.0f;
            }
      }
       
          // movimento inseto 
          
          if(currentFrameBackground == 1 && inseto.morto == false){
              if(   inseto.positionWidth <=1500 &&  i == 1 ){
                  
                      inseto.positionWidth  += 5;
                      
                  
              } else if ( i == 1 ) {
                  i=2;
                     
                  
              } else if(i==2 && ( inseto.positionWidth >=1500 || inseto.positionWidth >=500)){
                  
                   inseto.positionWidth  -= 5;
                   
              }else{
                  i=1;
              }
          }
          
          //boss
          
          
           // movimento mboss
           
           if(boss.life <= 100){
               
              if(currentFrameBackground == 3 && boss.morto == false){
              if(   boss.positionWidth <=1700 &&  i == 1 ){
                  
                  if(boss.positionHeight >=250 && boss.positionWidth <=600 ){
                      
                      
                        boss.positionHeight -=12;

                    }else if (boss.positionHeight <=750){
                        boss.positionHeight +=12;
                        
                        
                    }
                      boss.positionWidth  += 12;

              } else if ( i == 1 ) {
                  i=2;
                     
                  
              } else if(i==2 && ( boss.positionWidth >=1700 || boss.positionWidth >=300)){
                  
                   if(boss.positionHeight >=250 && boss.positionWidth >=600) {
                        boss.positionHeight -=12;
                    }else if (boss.positionHeight <=750){
                        boss.positionHeight +=12;
                    }
                      boss.positionWidth  -= 12;

              }else{
                  i=1;
              }
          }

           //----------------Normal----------------    
           }else{
               
                    if(currentFrameBackground == 3 && boss.morto == false){
              if(   boss.positionWidth <=1700 &&  i == 1 ){
                    
                      boss.positionWidth  += 5;
                      
              
                   
                  
              } else if ( i == 1 ) {
                  i=2;
                     
                  
              } else if(i==2 && ( boss.positionWidth >=1700 || boss.positionWidth >=300)){
                     ataque_florhit = true;
                   boss.positionWidth  -= 5;
                   
                   
              }else{
                  i=1;
              }
          }
           }

     
          // animação bosss
          
             elapsed += GetFrameTime();//Adiciona o tempo decorrido desde o último frame ao tempo total decorrido.
            
            if (elapsed >= frameTime){//Verifica se tempo decorrido é maior ou igual ao tempo que o quadro atual deve ser exibido.

                currentFrameBoss++;// Incrementa o índice do quadro atual.
                
                if (currentFrameBoss >=  frameCountBoss  ){//Verifica se o índice do quadro atual ultrapassou o número total de quadros na animação. Se sim, volta ao primeiro quadro.
                    currentFrameBoss= 0;
                }
                
                elapsed = 0.0f;
            }

          //------------------------------------------------------------------------------------------------
          
          //Fire boll
          
          elapsed += GetFrameTime();//Adiciona o tempo decorrido desde o último frame ao tempo total decorrido.
            
            if (elapsed >= frameTime){//Verifica se tempo decorrido é maior ou igual ao tempo que o quadro atual deve ser exibido.
            
                currentFramefireboll++;// Incrementa o índice do quadro atual.
                
                if (currentFramefireboll >= frameCountfireboll){//Verifica se o índice do quadro atual ultrapassou o número total de quadros na animação. Se sim, volta ao primeiro quadro.
                    currentFramefireboll= 0;
                }
                
                elapsed = 0.0f;
            }
          //florhit
             elapsed_flor += GetFrameTime() ;//Adiciona o tempo decorrido desde o último frame ao tempo total decorrido.
            
            if (elapsed_flor >= frameTime_flor){//Verifica se tempo decorrido é maior ou igual ao tempo que o quadro atual deve ser exibido.
            
                currentFrameflorhit++;// Incrementa o índice do quadro atual.
                
                if (currentFrameflorhit >= frameCountflorhit){//Verifica se o índice do quadro atual ultrapassou o número total de quadros na animação. Se sim, volta ao primeiro quadro.
                    currentFrameflorhit= 0;
                }
                
                elapsed_flor = 0.0f;
            }

        //-----------------------------------------------------------------------------------------------------------------------------------
                // Colisção 
                
                //Mapiamento do cavaleiro
                Rectangle cavaleiro  = {person.positionWidth+10, person.positionHeight+10,frameWidth-20, frameHeight-10};
                
                Vector2 person_position = {  person.positionWidth, person.positionHeight};
                Rectangle frame = {currentFrame * frameWidth , 0, frameWidth, frameHeight };
                
                //Mapiamento do Inseto   
                
                Rectangle inseto_position = { inseto.positionWidth+10, inseto.positionHeight+10, frameWidthInseto-20, frameHeightInseto-10 };
                
                //mapiamento boss
                Rectangle boss_position = { boss.positionWidth+10, boss.positionHeight+10, frameWidthBoss-20, frameHeightBoss-10 };
                
                //mapiamento florhit
                Rectangle florhit_position = { florHit.positionWidth+10, florHit.positionHeight+10, frameWidthflorhit-20, frameHeightflorhit-10 };
                
                //Mapiamento da fireboll
                
                  Rectangle fireboll_position = { fireBoll.positionWidth+10, fireBoll.positionHeight+10, frameWidthfireboll-20, frameHeightfireboll-10 };
                
                //Colisao
                
                
                  if(currentFrameBackground == 3 &&  boss.morto==false && person.morto == false){
                      collision_flor = CheckCollisionRecs(florhit_position, cavaleiro );
                     
                 }else{
                       collision_flor = false;
                     
                 }
                
                
                 if(currentFrameBackground == 1 &&  inseto.morto==false && person.morto == false){
                      collision = CheckCollisionRecs(inseto_position, cavaleiro );
                     
                 }else{
                       collision = false;
                     
                 }
                 
                    if(currentFrameBackground == 3 &&  boss.morto==false && person.morto == false){
                      collision_boss = CheckCollisionRecs(boss_position, cavaleiro );
                     
                 }else{
                       collision_boss = false;
                     
                 }
                
                
                
                 
                if(currentFrameBackground == 1 &&  inseto.morto==false  &&   ataque_fireBoll == true ){
                 
                 
                  atk_fireboll = CheckCollisionRecs(inseto_position, fireboll_position );
                  
                }else{
                      atk_fireboll = false;  
                
                     }  
                
                if(currentFrameBackground == 3 && boss.morto==false  &&   ataque_fireBoll == true){
                  atk_fireboll_boss = CheckCollisionRecs(boss_position, fireboll_position );
                  }else{
                      atk_fireboll_boss = false;  
                    
                     }  
                
                
                  
                  
                 // DAno boss
                 
                 
                   elapsed_hit += GetFrameTime();
                 
                        
                  if (elapsed_hit >= frameTime_hit){
                      if(collision_boss==true   ||  collision_flor==true){
                          person.life-= 15;
                          currentFrame = 6;
                          PlaySound(hit_boneco);
                               currentFrameLife++;
                
                          elapsed_hit =0;
                      }
                  }
                 
        
                   // DAno inseto
                 
                 elapsed_hit += GetFrameTime();
                 
                        
                  if (elapsed_hit >= frameTime_hit){
                      if(collision==true){
                          person.life-= 15;
                          currentFrame = 6;
                          PlaySound(hit_boneco);
                               currentFrameLife++;
                
                          elapsed_hit =0;
                      }
                  }
                  
                  
                  
                   // DAno bola de fogo
                 
                   elapsed_hit += GetFrameTime();
                 
                        
                  if (elapsed_hit >= frameTime_hit){
                      if(atk_fireboll ==true ){
                          inseto.life-= 15;
                          currentFrameInseto= 4;
                          if(inseto.life <=0)inseto.morto =true;
                               
                
                          elapsed_hit =0;
                      }
                  }
                  
                  //bola de fogo no boss
                   elapsed_hit += GetFrameTime();
                 
                        
                  if (elapsed_hit >= frameTime_hit){
                      if(atk_fireboll_boss == true ){
                          boss.life-= 10;
                           currentFramebarra_life_boss++;
                         
                          if(boss.life <=0)boss.morto =true;
                               
                
                          elapsed_hit =0;
                      }
                  }
                  
                  
               if(person.life <=0)person.morto =true;
                 
             
                
        
         //-----------------------------------------------------------------------------------------------------------------
        // Draw animation
        BeginDrawing();
        // ------------------------------------ DESENHA O MAPA __________________________________________________
        DrawTextureRec(Background, (Rectangle){ currentFrameBackground * frameWidthBackground , 0, frameWidthBackground, frameHeightBackground }, (Vector2){ 0, 0 }, WHITE);
        // ------------------------------------ DESENHA OS TITULOS E INFORMAÇÔES __________________________________________________
            ClearBackground(RAYWHITE);
            
           if(aviso == false && currentFrameBackground == 0){
              if(IsKeyDown(KEY_ENTER)){aviso = true; }
             DrawRectangle( 500, 30, 1000, 250 , BLACK);
             DrawText(TextFormat("O TERRIVEL COGUPOUVO"), 700, 40, 50, WHITE);
            DrawText(TextFormat("O grande mago Fire, se prepara para entrar na floresta "), 540, 120, 30, WHITE);
           DrawText(TextFormat("replata de monstros com o objetivo de matar Cogupouvo."), 540, 160, 30, WHITE);
            DrawText(TextFormat("Enter>>."), 1300, 250, 30, WHITE);
           }
           
         // -------------------------------------------------------------------------------------------------------------------------

        
     
         
       
       // Inseto:
          if(currentFrameBackground == 1){
          DrawTextureRec(Inseto,(Rectangle){frameWidthInseto * currentFrameInseto,0 ,frameWidthInseto ,frameHeightInseto },(Vector2){  inseto.positionWidth , inseto.positionHeight }, inseto.color);
          }
          
          
            //vida
        if(boss.morto == false && currentFrameBackground == 3 )
        DrawTextureRec(barra_life_boss,(Rectangle){frameWidthbarra_life_boss * currentFramebarra_life_boss,0,frameWidthbarra_life_boss,frameHeightbarra_life_boss},(Vector2 ){ 450, -400} ,person.color);
          //boss
            if(currentFrameBackground == 3){
          DrawTextureRec(Boss,(Rectangle){frameWidthBoss * currentFrameBoss ,0 ,frameWidthBoss ,frameHeightBoss },(Vector2){  boss.positionWidth , boss.positionHeight }, boss.color);
          }
         
        //vida
        if(person.morto == false)
        DrawTextureRec(Life,(Rectangle){frameWidthLife * currentFrameLife,0,frameWidthLife,frameHeightLife},(Vector2 ){ person.positionWidth, person.positionHeight-80} ,person.color);
         // Cavaleiro:
        DrawTextureRec(spritesheet,frame,person_position, person.color);  
        
         //fireboll
        if( ataque_fireBoll == true){
            DrawTextureRec(fireboll,(Rectangle){frameWidthfireboll * currentFramefireboll, 0 ,frameWidthfireboll ,frameHeightfireboll },(Vector2){   fireBoll.positionWidth,  fireBoll.positionHeight }, fireBoll.color);
        }
       //florhit 
          if(boss.morto == false && currentFrameBackground == 3 )
            DrawTextureRec(florhit ,(Rectangle){frameWidthflorhit  * currentFrameflorhit , 0 ,frameWidthflorhit  ,frameHeightflorhit  },(Vector2){  florHit.positionWidth,  florHit.positionHeight }, florHit.color);
       
       
         
        florHit.positionWidth = boss.positionWidth - 200;
         
        EndDrawing();
    
}while (!WindowShouldClose());
UnloadMusicStream(music);
    UnloadTexture(Inseto);
    UnloadTexture(Life);
    UnloadTexture(Background);
    UnloadTexture(spritesheet);
    CloseWindow();
    return 0;
}
