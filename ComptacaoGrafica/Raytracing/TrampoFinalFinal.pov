// PoVRay 3.7 Scene File " ... .pov"
// author:  ...
// date:    ...
//--------------------------------------------------------------------------
#version 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"
//--------------------------------------------------------------------------
// camera ------------------------------------------------------------------
#declare Camera_0 = camera {/*ultra_wide_angle*/ angle 75      // front view
                            location  <0 , 3.5 ,-4.7>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_1 = camera {/*ultra_wide_angle*/ angle 65   // diagonal view
                            location  <2.8 , 4 ,-5>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
                            
                            
#declare Camera_2 = camera {/*ultra_wide_angle*/ angle 90 // right side view
                            location  <2 , 2.0 , -1.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}                            
                            

#declare Camera_3 = camera {/*ultra_wide_angle*/ angle 90        // top view
                            location  <0 , 3.5 ,-0.005>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}     
                            
                            
#declare Camera_3 = camera {/*ultra_wide_angle*/ angle 90        // top view
                            location  <0 , 2 ,2>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
                            
                            
 #declare Camera_4 = camera {/*ultra_wide_angle*/ angle 75      // front view
                            location  <0 , 1.5 ,-2>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.5 , 0.0>}


                            
#declare Camera_5 = camera {/*ultra_wide_angle*/ angle 90 // right side view
                            location  <3.0 , 1.5 , 0.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 0.8 , 0.0>}                            


                            
camera{Camera_5}
// sun ---------------------------------------------------------------------
light_source{<1500,2500,-2500> color White}

// sky ---------------------------------------------------------------
sky_sphere{ pigment{ color rgb<0,1,0.5>*0.3
                     
                      rotate< 0,0, 0>  
                   
                     scale 2 }
           } // end of sky_sphere
 
//------------------------------ the Axes --------------------------------
 
//------------------------------------------------------------------------
#macro Axis_( AxisLen, Dark_Texture,Light_Texture) 
 union{
    cylinder { <0,-AxisLen,0>,<0,AxisLen,0>,0.05
               texture{checker texture{Dark_Texture } 
                               texture{Light_Texture}
                       translate<0.1,0,0.1>}
             }
    cone{<0,AxisLen,0>,0.2,<0,AxisLen+0.7,0>,0
          texture{Dark_Texture}
         }
     } // end of union                   
#end // of macro "Axis()"
//------------------------------------------------------------------------
#macro AxisXYZ( AxisLenX, AxisLenY, AxisLenZ, Tex_Dark, Tex_Light)
//--------------------- drawing of 3 Axes --------------------------------
union{
#if (AxisLenX != 0)
 object { Axis_(AxisLenX, Tex_Dark, Tex_Light)   rotate< 0,0,-90>}// x-Axis
 text   { ttf "arial.ttf",  "x",  0.15,  0  texture{Tex_Dark} 
          scale 0.5 translate <AxisLenX+0.05,0.4,-0.10>}
#end // of #if 
#if (AxisLenY != 0)
 object { Axis_(AxisLenY, Tex_Dark, Tex_Light)   rotate< 0,0,  0>}// y-Axis
 text   { ttf "arial.ttf",  "y",  0.15,  0  texture{Tex_Dark}    
           scale 0.5 translate <-0.75,AxisLenY+0.50,-0.10>}
#end // of #if 
#if (AxisLenZ != 0)
 object { Axis_(AxisLenZ, Tex_Dark, Tex_Light)   rotate<90,0,  0>}// z-Axis
 text   { ttf "arial.ttf",  "z",  0.15,  0  texture{Tex_Dark}
               scale 0.5 translate <-0.75,0.2,AxisLenZ+0.10>}
#end // of #if 
} // end of union
#end// of macro "AxisXYZ( ... )"
//------------------------------------------------------------------------

#declare Texture_A_Dark  = texture {
                               pigment{ color rgb<1,0.45,0>}
                               finish { phong 1}
                             }
#declare Texture_A_Light = texture { 
                               pigment{ color rgb<1,1,1>}
                               finish { phong 1}
                             }

//object{ AxisXYZ( 4.5, 3.0, 5, Texture_A_Dark, Texture_A_Light) scale 0.25}
//-------------------------------------------------- end of coordinate axes


//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------




 // CHAO
 box { <-1.00, 0.00, -1000>,< 1.00, 0.001, 1000>   
      
      
             texture{ pigment{ checker color White color Black }   
                finish { phong 1 } 
                rotate<0,0,0> scale 0.25 translate<0,0,0>
              } // end of texture 

      
      scale <2,2,2> rotate<0,90,0> translate<0,-1,-1.5> 
    } // end of box --------------------------------------


    




  
//-------------------------------------CENARIO------------------------------  
  
  
  merge{
               
        //caixa gaveetas
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
     
      
            scale <0.55,0.8,0.4> rotate<0,0,0> translate<-1.3,-1,0> 
           } // end of box --------------------------------------

  
  
  
       //caixa cima
  
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   


        scale <1.7,0.1,0.415> rotate<0,0,0> translate<-0.15,0.6,0> 
        } // end of box --------------------------------------


        
        //pe direito
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
      
      
      
            scale <0.1,0.8,0.415> rotate<0,0,0> translate<1.45,-1,0> 
        } // end of box --------------------------------------

        
       
       
       texture{ pigment{ color rgb<0.85,0.35,0.05>*0.25 }
                 normal { pigment_pattern{ wood frequency 5 
                                           sine_wave turbulence 0.05
                                           color_map {[0.0, rgb 0]
                                                      [0.2, rgb 0.5]
                                                      [0.8, rgb 0.5]
                                                      [1.0, rgb 0]}
                                           rotate< 90,0,0> scale 0.5}
                          0.15 }
                 finish { phong 1 reflection 0.01}
               } // end of texture ------------------------------------- 

  }
   
   
   
   
   
        
         
        // gaveetas
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
     
            
            
          texture{ pigment{ color rgb<0.85,0.35,0.05>*0.25 }
                 normal { pigment_pattern{ wood frequency 5 
                                           sine_wave turbulence 0.05
                                           color_map {[0.0, rgb 0]
                                                      [0.2, rgb 0.5]
                                                      [0.8, rgb 0.5]
                                                      [1.0, rgb 0]}
                                           rotate< 90,0,0> scale 0.5}
                          0.15 }
                 finish { phong 1 reflection 0.01}
               } // end of texture ------------------------------------- 

            
            
            
            scale <0.5,0.25,0.3> rotate<0,0,0> translate<-1.28,0.05,-0.16> 
           } // end of box -------------------------------------- 
           
           
           
           
                   // gaveetas
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
     
            
            
          texture{ pigment{ color rgb<0.85,0.35,0.05>*0.25 }
                 normal { pigment_pattern{ wood frequency 5 
                                           sine_wave turbulence 0.05
                                           color_map {[0.0, rgb 0]
                                                      [0.2, rgb 0.5]
                                                      [0.8, rgb 0.5]
                                                      [1.0, rgb 0]}
                                           rotate< 90,0,0> scale 0.5}
                          0.15 }
                 finish { phong 1 reflection 0.01}
               } // end of texture ------------------------------------- 

            
            
            
            scale <0.5,0.25,0.3> rotate<0,0,0> translate<-1.28,-0.5,-0.16> 
           } // end of box --------------------------------------
           
           
           
           
           sphere { <0,0,0>, 0.5 

        texture { pigment{ color rgb 0}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale 0.13  rotate<0,0,0>  translate<-1.25,0.33,-0.5>  
       }  // end of sphere ----------------------------------- 
                        
                        
        sphere { <0,0,0>, 0.5 

        texture { pigment{ color rgb 0}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale 0.13  rotate<0,0,0>  translate<-1.25,-0.23,-0.5>  
       }  // end of sphere -----------------------------------  
       
       
       
        //calendario
       
    merge{ 
  
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<1.00, 1.00, 1.00>}  
                  finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

            scale <1,1,0.1> rotate<0,0,0> translate<0,0.5,0> 
        } // end of box --------------------------------------
  
    
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<1.00, 0, 0>*0.8}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

            scale <1.045,0.1,0.11> rotate<0,0,0> translate<0,2.5,-0.05> 
     } // end of box --------------------------------------  
    
    
   
   
   //Bevelled_Text(Font, String, Cuts, BevelAng, BevelDepth, Depth, Offset, UseMerge)
        object{ 
            Bevelled_Text("arial.ttf", "19", 10 , 35, 0.045, 1, 0.00, 0)
            texture{ pigment{ color rgb 0} 
                 //normal { bumps 0.5 scale 0.005}
                 //finish { specular 1 reflection 0}
               } // end of texture
            rotate<0,0,0>
            scale<0.75,1.0,0.1>*1.6 
            translate<-0.6, 1.2,-0.2>
        } // end of Bevelled_Text object -------------------------------------------
 
    
    
        //Bevelled_Text(Font, String, Cuts, BevelAng, BevelDepth, Depth, Offset, UseMerge)
        object{ 
            Bevelled_Text("arial.ttf", "JUNE", 10 , 35, 0.045, 1, 0.00, 0)
            texture{ pigment{ color rgb 0} 
                 //normal { bumps 0.5 scale 0.005}
                 //finish { specular 1 reflection 0}
               } // end of texture
            rotate<0,0,0>
            scale<0.75,1.0,0.15>*0.4 
            translate<-0.4, 0.72,-0.15>
        } // end of Bevelled_Text object -------------------------------------------
        
      scale 0.35  translate <-2,1.9,0>
        
    } 
    
 
 
 
 
 
 
    
    
 //------------------------ COLIN ------------------------------------------------------------
 
 
 
 
 
 
union{


//BASE COLIN
object{ // Round_Box(A, B, WireRadius, UseMerge)
        Round_Box(<-1,0,-1>,<1,1,1>, 0.2   , 0)  
         
        texture{ pigment{ color rgb<1,0.8,0.5>}
               //normal { radial sine_wave frequency 30 scale 0.25 }
                 finish { phong 1 }
                }
        scale<0.4,0.2,0.4>  rotate<0, 0,0> translate<0,0.1,0>
      } // --------------------------------------------------------- 

 
//TRONCO COLIN
 object{ // Round_Box(A, B, WireRadius, UseMerge)
        Round_Box(<-1,0,-1>,<0.8,2.8,0.8>, 0.25   , 0)  
         
        texture{ pigment{ color rgb<1,0.8,0.5>}
               //normal { radial sine_wave frequency 30 scale 0.25 }
                 finish { phong 1 }
                }
        scale<0.3,0.25,0.2>  rotate<0,0,0> translate<0.03,0.2,0.15>
      } // ---------------------------------------------------------   


//BUNDINHA COLIN 
object{ // Round_Box(A, B, WireRadius, UseMerge)
        Round_Box(<-1,0,-1>,<1,1,1>, 0.25   , 0)  
         
        texture{ pigment{ color rgb<1,0.8,0.5>}
               //normal { radial sine_wave frequency 30 scale 0.25 }
                 finish { phong 1 }
                }
        scale<0.4,0.6,0.2>  rotate<0,0,0> translate<0,0.7,0.18>
      } // --------------------------------------------------------- 


 
/* 
//TELA 
object{ // Round_Box(A, B, WireRadius, UseMerge)
        Round_Box(<-1,0,-1>,<1,1,1>, 0.25   , 0)  
         
        texture{ pigment{ color rgb<1,0.8,0.5>}
               //normal { radial sine_wave frequency 30 scale 0.25 }
                 finish { phong 1 }
                }
        scale<0.7,1,0.22>  rotate<0,0,0> translate<0,0.55,0>
      } // --------------------------------------------------------- */
 




 //TELA

union{ 
 
          
      difference{
 //TELA 
        object{ // Round_Box(A, B, WireRadius, UseMerge)
            Round_Box(<-1,0,-1>,<1,1,1>, 0.25   , 0)  
         
            texture{ pigment{ color rgb<1,0.8,0.5>}
               //normal { radial sine_wave frequency 30 scale 0.25 }
                 finish { phong 1 }
                }
            scale<0.7,1.08,0.22>  rotate<0,0,0> translate<0,0.46,0>
            } // --------------------------------------------------------- */
           
        //parafuso dir
        sphere { <0,0,0>, 0.5 

            texture { pigment{ color rgb<1, 1, 1>*0.3}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

            scale<0.1,0.1,0.05>  rotate<0,0,0>  translate<0.55,1.42,-0.22>  
            }  // end of sphere ----------------------------------- 
       
         sphere { <0,0,0>, 0.5 

               texture { pigment{ color rgb<1, 1, 1>*0.3}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

                scale<0.1,0.1,0.05>  rotate<0,0,0>  translate<-1,1.42,-0.22>  
            }  // end of sphere -----------------------------------  
             
             
           //parafuso esq  
              sphere { <0,0,0>, 0.5 

               texture { pigment{ color rgb<1, 1, 1>*0.3}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

                scale<0.1,0.1,0.05>  rotate<0,0,0>  translate<-0.55,1.42,-0.22>  
            }  // end of sphere -----------------------------------    
       
       
              
          //buraco    
               box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

            scale <0.32,0.2,0.1> rotate<0,0,0> translate<0,0.98,-0.2> 
        } // end of box --------------------------------------
       
       
         //olho dir - iris
        
                 box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<0, 0, 0>}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.05,0.065,0.1> rotate<0,0,0> translate<0.43,0.68,-0.15> 
                } // end of box --------------------------------------   
         
       
       
               //olho esq - iris
        
                 box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<0, 0, 0>}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.05,0.065,0.1> rotate<0,0,0> translate<-0.38,0.68,-0.15> 
                } // end of box --------------------------------------     
         
     
          
             
                 box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1,0,0>}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                    scale <0.215,0.06,0.05> rotate<0,0,0> translate<0,0.57,-0.22> 
                } // end of box --------------------------------------
       
       
       } 
        
        
        //visor
      
      
      
       difference{
                
                //birda visor
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1,0.8,0.5>*0.8}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                    } // end of texture

                    scale <0.37,0.23,0.1> rotate<0,0,0> translate<0,0.975,-0.15> 
                } // end of box --------------------------------------
       
       
       
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<0, 0, 0>}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.32,0.2,0.1> rotate<0,0,0> translate<0,0.999,-0.2> 
                } // end of box --------------------------------------
           
          
          }
          
       
    
    union{    
             //olho dir - branco
             
               
          difference{   
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<1, 1, 1>}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.086,0.085,0.1> rotate<0,0,0> translate<0.4,0.68,-0.125> 
                } // end of box --------------------------------------      
           
       
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                 texture { pigment{ color rgb<0, 0, 0>}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.05,0.065,0.1> rotate<0,0,0> translate<0.42,0.7,-0.15> 
                    } // end of box --------------------------------------   
           }  
           
          
            
                      
            //olho dir - bordas
           difference{
         
             box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<1,0.8,0.5>*0.8}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.105,0.105,0.1> rotate<0,0,0> translate<0.4,0.665,-0.125> 
                } // end of box --------------------------------------  
            
             box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                 texture { pigment{ color rgb<0, 0, 0>}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.05,0.065,0.1> rotate<0,0,0> translate<0.42,0.7,-0.15> 
                    } // end of box -------------------------------------- 
              }
              
              translate<0,-0.02,0> 
        }
        
        
        
        
        
        
        union{    
             //olho esq - branco
             
               
          difference{   
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<1, 1, 1>}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.086,0.085,0.1> rotate<0,0,0> translate<0.4,0.68,-0.125> 
                } // end of box --------------------------------------      
           
       
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                 texture { pigment{ color rgb<0, 0, 0>}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.05,0.065,0.1> rotate<0,0,0> translate<0.42,0.7,-0.15> 
                    } // end of box --------------------------------------   
           }  
           
          
            
                      
            //olho esq - bordas
           difference{
         
             box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

            texture { pigment{ color rgb<1,0.8,0.5>*0.8}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.105,0.105,0.1> rotate<0,0,0> translate<0.4,0.665,-0.125> 
                } // end of box --------------------------------------  
            
             box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                 texture { pigment{ color rgb<0, 0, 0>}  
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                 } // end of texture

                scale <0.05,0.065,0.1> rotate<0,0,0> translate<0.42,0.7,-0.15> 
                    } // end of box -------------------------------------- 
              }
         
         translate <-0.8,-0.02,0>      
        }
        
              
   
   
         difference{          
           
               //boca labios?
              object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<-1,0,-1>,<1,1,1>, 0.25   , 0)  
         
                texture{ pigment{ color rgb<1,0.8,0.5>*0.6}
                  //normal { radial sine_wave frequency 30 scale 0.25 }
                 finish { phong 1 }
                        }
                scale<0.22,0.32,0.05>  rotate<0, 0,0> translate<0,0.45,-0.19>
                } // ---------------------------------------------------------

     
              //buraco boca
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<0,0,0>}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                    scale <0.215,0.06,0.05> rotate<0,0,0> translate<0,0.57,-0.22> 
                } // end of box --------------------------------------
 
         }
         
        //union dentes cima
        union{   
                         //dente
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1,1,1>}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                    scale <0.05,0.02,0.02> rotate<0,0,0> translate<0.16,0.648,-0.215> 
                } // end of box --------------------------------------
         
         
                   //dente
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1,1,1>}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                    scale <0.05,0.02,0.02> rotate<0,0,0> translate<0.055,0.648,-0.215> 
                } // end of box --------------------------------------
         
        
                //dente
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1,1,1>}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                    scale <0.053,0.02,0.02> rotate<0,0,0> translate<-0.0523,0.648,-0.215> 
                } // end of box --------------------------------------
         
               
               
               
                //dente
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1,1,1>}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                    scale <0.05,0.02,0.02> rotate<1,1,1> translate<-0.16,0.648,-0.215> 
                } // end of box --------------------------------------
                
            }
               
         
         
                 //union dentes baixo
        union{   
                         //dente
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1,1,1>}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                    scale <0.05,0.02,0.02> rotate<0,0,0> translate<0.16,0.648,-0.215> 
                } // end of box --------------------------------------
         
         
                   //dente
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1, 0.8745,0>}  
                    finish { phong 1 reflection{ 0.02 metallic 40} }        
                    } // end of texture

                    scale <0.05,0.02,0.02> rotate<0,0,0> translate<0.055,0.648,-0.215> 
                } // end of box --------------------------------------
         
        
                //dente
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1,1,1>}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                    scale <0.053,0.02,0.02> rotate<0,0,0> translate<-0.0523,0.648,-0.215> 
                } // end of box --------------------------------------
         
               
               
               
                //dente
                box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

                    texture { pigment{ color rgb<1,1,1>}  
                    finish { phong 1 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                    scale <0.05,0.02,0.02> rotate<0,0,0> translate<-0.16,0.648,-0.215> 
                } // end of box --------------------------------------
             
             
             
             translate<0,-0.08,0>
                
            }
         
         
  
  
  
  
  
 merge{
 

   cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,0.8,0.2> rotate<0,0,0> translate<0,0.5,0>
         } // end of cylinder -------------------------------------
                              
                              
   cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,0.8,0.2> rotate<0,0,0> translate<-0.3,0.5,0>
         } // end of cylinder -------------------------------------    
         
         
         
            cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,0.8,0.2> rotate<0,0,0> translate<-0.62,0.5,0>
         } // end of cylinder -------------------------------------
         
         
         
        cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,0.8,0.2> rotate<0,0,0> translate<-0.88,0.5,0>
         } // end of cylinder -------------------------------------
         
         
         
         
          cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,0.8,0.2> rotate<0,0,0> translate<0.3,0.5,0>
         } // end of cylinder -------------------------------------
         
         
         
          cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,0.8,0.2> rotate<0,0,0> translate<0.6,0.5,0>
         } // end of cylinder ------------------------------------- 
         
         
         
         
        cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,0.8,0.2> rotate<0,0,0> translate<0.88,0.5,0>
         } // end of cylinder ------------------------------------- 
         
         
         
        cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,0.8,0.2> rotate<0,0,0> translate<1.15,0.5,0>
         } // end of cylinder -------------------------------------
         
     
     //verticais    
         
 
          cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,1.15,0.2> rotate<0,0,90> translate<1.3,1.8,0>
         } // end of cylinder -------------------------------------
         
         
         
            cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,1.15,0.2> rotate<0,0,90> translate<1.3,1.5,0>
         } // end of cylinder ------------------------------------- 
         
         
         
            cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,1.15,0.2> rotate<0,0,90> translate<1.3,1.15,0>
         } // end of cylinder -------------------------------------  
         
         
         
         
            cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0.6,0.2> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.02 metallic 10} } 
                   } // end of texture
                                                      
                                                      
                                                      
           scale <0.2,1.15,0.2> rotate<0,0,90> translate<1.3,0.8,0>
         } // end of cylinder -------------------------------------                                    
         
   
   
      //Bevelled_Text(Font, String, Cuts, BevelAng, BevelDepth, Depth, Offset, UseMerge)
        object{ 
        Bevelled_Text("arial.ttf", "HELLO.", 10 , 35, 0.045, 1, 0, 0)
        texture{ pigment{ color rgb<0,0,1>*0.8 } 
                 //normal { bumps 0.5 scale 0.005}
                 finish { specular 1 reflection 0}
               } // end of texture
        rotate<0,0,0>
        scale<0.75,1.1,0.1>*0.8 
        translate<-0.8, 0.93,-0.11>
      } // end of Bevelled_Text object -------------------------------------------
  
  
  
   scale <0.28,0.24,0.23> translate<-0.041,0.88,-0.23> 
    }
                
    
    scale <0.98,0.91,0.9>  translate<0,0.15,0.01>   rotate <0,0,0>
 }




















       

// BARRA LATERAL DIR
difference{

object{ // Round_Box(A, B, WireRadius, UseMerge)
        Round_Box(<-1,0,-1>,<1,1,1>, 0.25   , 0)  
         
        texture{ pigment{ color rgb<1,0.8,0.5>}
               //normal { radial sine_wave frequency 30 scale 0.25 }
                 finish { phong 1 }
                }
        scale<0.05,0.35,0.1>  rotate<0, 0,0> translate<0.7,1,0>
      } // ---------------------------------------------------------
cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<1,0.8,0.5> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture

           scale <0.4,0.06,0.05> rotate<90,0,0> translate<0.75,1.27,-0.06>
         } // end of cylinder -------------------------------------        
         
         
cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<1,0.8,0.5> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture

           scale <0.4,0.06,0.05> rotate<90,0,0> translate<0.75,1.2,-0.06>
         } // end of cylinder -------------------------------------
         
         
cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<1,0.8,0.5> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture

           scale <0.4,0.06,0.05> rotate<90,0,0> translate<0.75,1.13,-0.06>
         } // end of cylinder -------------------------------------   
         
       cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<1,0.8,0.5> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture

           scale <0.4,0.06,0.05> rotate<90,0,0> translate<0.75,1.07,-0.06>
         } // end of cylinder -------------------------------------         

                    
}
// FIM BARRA LATERAL
 
 
// BARRA LATERAL ESQ
difference{

            object{ // Round_Box(A, B, WireRadius, UseMerge)
                Round_Box(<-1,0,-1>,<1,1,1>, 0.25   , 0)  
         
                texture{ pigment{ color rgb<1,0.8,0.5>}
                    //normal { radial sine_wave frequency 30 scale 0.25 }
                 finish { phong 1 }
                }
                scale<0.05,0.35,0.1>  rotate<0, 0,0> translate<-0.7,1,0>
            } // ---------------------------------------------------------
            cylinder { <0,0,0>,<0,2.00,0>, 0.30 

                    texture { pigment { color rgb<1,0.8,0.5> }
                        //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture

                scale <0.4,0.06,0.05> rotate<90,0,0> translate<-0.75,1.27,-0.06>
            } // end of cylinder -------------------------------------        
         
         
            cylinder { <0,0,0>,<0,2.00,0>, 0.30 

                    texture { pigment { color rgb<1,0.8,0.5> }
                        //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                       finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                       } // end of texture

                     scale <0.4,0.06,0.05> rotate<90,0,0> translate<-0.75,1.2,-0.06>
            } // end of cylinder -------------------------------------
         
         
            cylinder { <0,0,0>,<0,2.00,0>, 0.30 

                    texture { pigment { color rgb<1,0.8,0.5> }
                        //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                        } // end of texture

                scale <0.4,0.06,0.05> rotate<90,0,0> translate<-0.75,1.13,-0.06>
             } // end of cylinder -------------------------------------   
         
            cylinder { <0,0,0>,<0,2.00,0>, 0.30 

                texture { pigment { color rgb<1,0.8,0.5> }
                     //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                    } // end of texture

                scale <0.4,0.06,0.05> rotate<90,0,0> translate<-0.75,1.07,-0.06>
            } // end of cylinder ------------------------------------- 

                    
    }// FIM BARRA LATERAL //--------------------------------------------------------------------------




#include "shapes3.inc"


  

 
 
union { 
//BRA�O DIREITO
//--------------------------------------------------------------------------
object{ Segment_of_Torus ( 1.10, // radius major, 
                           0.17, // radius minor, 
                           -100  // segment angle (in degrees)
                         ) //-----------------------------------
        texture { pigment{ color rgb<0,0,0>}  
                  finish { phong 1}
                } // end of texture 50
        scale <0.3,0.3,0.3> rotate<3,0,0> translate<0.75,0.9,-0.32>
      } // end of Torus_Segment(...) ---------------------------              
//--------------------------------------------------------------------------
    
   


          
 
 
 
  cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0,0> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture
                                          //-40
           scale <0.15,0.4,0.16> rotate<-85,0,0> translate<1.086,0.9,-0.3>
         } // end of cylinder -------------------------------------
        
        

       
         
 
 
         
   
 // linear prism in y-direction: from .. ,to ..,number of points (first = last)
prism { 0.00 ,2.00 , 4
       <-1.00, 0.00>, // first point
       < 1.00, 0.00>, 
       < 0.00,-1.50>,
       <-1.00, 0.00>  // last point = first point !!!

       texture { pigment{ color White } 
                 finish { phong 1.0 }
               } // end of texture

       scale <0.25, 0.06, 0.3>
       rotate<10,0,0> 
       translate<1.1, 0.9, -1> 
     } // end of prism --------------------------------------------------------
     
     
       
               cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<1,1,1> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture
                                          //-40
           scale <0.2,0.1,0.15> rotate<88,7,0> translate<1.08,0.96,-1>
         } // end of cylinder -------------------------------------  
       
       
     
     }//union bra�o dir
     
    
    
         
         
         
 //BRA�O DIREITO FIM
                 
                 
                 
 //BRA�O ESQUERDO

merge{
 
 
 object{ Segment_of_Torus ( 1.10, // radius major, 
                           0.17, // radius minor, 
                           -100  // segment angle (in degrees)
                         ) //-----------------------------------
        texture { pigment{ color rgb<0,0,0>}  
                  finish { phong 1}
                } // end of texture 50
        scale <0.3,0.3,0.3> rotate<110,180,0> translate<-0.75,1.2,-0.2>
      } // end of Torus_Segment(...) ---------------------------              
//--------------------------------------------------------------------------
 



cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { pigment { color rgb<0,0,0> }
                   //normal  { bumps 0.5 scale <0.005,0.25,0.005>}
                     finish  { phong 0.5 reflection{ 0.00 metallic 0.00} } 
                   } // end of texture
                                          //-40
           scale <0.15,0.35,0.16> rotate<-20,0,0> translate<-1.08,1.2,-0.2>
         } // end of cylinder -------------------------------------  
         
         
 /*
 // linear prism in y-direction: from .. ,to ..,number of points (first = last)
prism { 0.00 ,2.00 , 4
       <-1.00, 0.00>, // first point
       < 1.00, 0.00>, 
       < 0.00,-1.50>,
       <-1.00, 0.00>  // last point = first point !!!

       texture { pigment{ color Black } 
                 finish { phong 1.0 }
               } // end of texture

       scale <0.25, 0.05, 0.3>
       rotate<90,0,0> 
       translate<-1.07, 2, -0.25> 
     } // end of prism -------------------------------------------------------- */        
  
  

}
//BRA�O ESQUERDO FIM

 
 
 
 
 //mao mouse
 
 
 
 
  union{

 
 
 difference{
   
   
  //mao 
  box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<1.00, 1.00, 1.00>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <1,1.36,0.12> rotate<0,0,0> translate<0,0.5,0> 
    } // end of box --------------------------------------
                            
                            
   //corte baixo
     box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <1.2,0.2,1> rotate<0,0,0> translate<0,0.2,0> 
    } // end of box --------------------------------------  
    

      
      //corte lateral direito 1     
       box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,1> rotate<90,0,0> translate<1.1,1.55,-0.2> 
    } // end of box -------------------------------------- 
      
      
      
      //lateral esquerda 1
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<-0.9,0.4,-0.2> 
    } // end of box --------------------------------------      
          
    
    
    
       //lateral esquerda 2   
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<-1,0.7,-0.2> 
    } // end of box --------------------------------------      
    
                 
       
      //lateral esquerda 3
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,2> rotate<90,0,0> translate<-1.1,0.7,-0.2> 
    } // end of box --------------------------------------          
                    
    
      
        
               
      //lateral esquerda 4-2        
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<-1,2.4,-0.2> 
    } // end of box --------------------------------------  
      
      
     
      
        
      //lateral esquerda 5-1
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<-0.9,2.55,-0.2> 
    } // end of box --------------------------------------   
             
             
        
      
        
      //lateral esquerda 1
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<-0.78,2.65,-0.2> 
    } // end of box --------------------------------------  
                        
        
     
           
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<-0.78,2.8,-0.2> 
    } // end of box --------------------------------------  
                        
     
             
           
        
     
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<-0.54,2.82,-0.2> 
    } // end of box --------------------------------------  
                    
             
            
     
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<-0.54,2.8,-0.2> 
    } // end of box --------------------------------------  
    
     
    
    
        
                 
     
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<-0.25,2.94,-0.2> 
    } // end of box --------------------------------------           
 
     
            
       
        
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.06,0.2,0.5> rotate<90,0,0> translate<0.4,2.8,-0.2> 
    } // end of box --------------------------------------   
     
     
     
           
    
           
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<0.65,2.95,-0.2> 
    } // end of box --------------------------------------   
     
    
    
              
            
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,1.4> rotate<90,0,0> translate<0.999,1.9,-0.2> 
    } // end of box --------------------------------------              
        
    
    
    
                
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<0.4,0.4,-0.2> 
    } // end of box --------------------------------------   
     
    
                    
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<0.5,0.7,-0.2> 
    } // end of box --------------------------------------  
    
    
    
    
      
                    
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<0.6,1.01,-0.2> 
    } // end of box -------------------------------------- 
    
    
   
    
        
                    
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<0.7,1.33,-0.2> 
    } // end of box --------------------------------------         
 
   
            
                    
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.5> rotate<90,0,0> translate<0.865,1.63,-0.2> 
    } // end of box --------------------------------------         
 
    
    
    
          //lateral corre��o      
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.2,0.2,0.6> rotate<90,0,0> translate<-1,2.7,-0.2> 
    } // end of box -------------------------------------- 
    
             
    
    
    } 

       

           box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.045,0.13,0.61> rotate<90,0,0> translate<0.3,2.58,-0.13> 
    } // end of box --------------------------------------
    
    
    
      box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.045,0.13,0.61> rotate<90,0,0> translate<0.01,2.58,-0.13> 
    } // end of box --------------------------------------    
    
    
    
    
          box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.045,0.13,0.17> rotate<90,0,0> translate<-0.35,2.14,-0.125> 
    } // end of box --------------------------------------     
    
    
    
    
    
            
          box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

      texture { pigment{ color rgb<0, 0, 0>}  
                finish { phong 1 reflection{ 0.00 metallic 0.00} } 
              } // end of texture

      scale <0.042,0.13,0.1> rotate<90,0,0> translate<-0.62,2.05,-0.125> 
    } // end of box --------------------------------------     
     
     
     
             //20,180,0
      rotate<18,180,0> scale 0.36  translate <-1.15,1.57,-0.35>
        
    } 
    
    
      scale 0.9  translate<0,0.71,0>
    }