#include <iostream>
#include <string>
#include <cstring>
#include <thread>
#include <chrono>
#include <cctype>
#include <cstdlib> // Required for std::system

#ifndef _WIN32
  #include <sys/ioctl.h>
  struct winsize w;
#endif

void clear(){
#ifdef _WIN32
  std::system("cls"); 
#else
  std::system("clear");
#endif
}

uint8_t d; //ABCD EFGH A=Extra?, B=Rope, C=K.Paulsen, D,Shovel, FGH=screenProgress
std::string in;

#define wait(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

void c(){
  while(true)
    c();
}

void anim(std::string s, int ms){
  for(int i=0; i < s.size(); ++i){
    std::cout<<s[i]<<std::flush;
    if(!std::isspace(static_cast<unsigned char>(s[i])))
      wait(ms);
  }
}

std::string center(std::string s){
  #ifndef _WIN32
    ioctl(0, TIOCGWINSZ, &w);
    if(s.size() > w.ws_col)
      return s;
    for(int i = 0; i <= (w.ws_col - s.size())/2; ++i)
      s = ' ' + s;
  #endif
  return s;
}

int main() {
  #ifndef _WIN32
    ioctl(0, TIOCGWINSZ, &w);
  #endif

  //title
  clear();
  #ifndef _WIN32
    std::cout
      <<"     █████▄  ▄▄▄  ▄▄    ▄▄▄▄▄   ██     ▄▄ ▄▄ ▄▄  ▄▄  ▄▄▄ \n"
      <<"     ██▄▄█▀ ██▀██ ██    ██▄▄    ██     ██ ██ ███▄██ ██▀██\n"
      <<"     ██     ██▀██ ██▄▄▄ ██▄▄▄   ██████ ▀███▀ ██ ▀██ ██▀██\n"
      <<"\nCaps Lock is recommended for this game.\nPress enter to start...";
  #else
    anim("P A L E  L U N A", 50);
    std::cout<<"\nCaps Lock is recommended for this game.\nPress enter to start...";
  #endif

  std::cin.get();

  //s1
  clear();
  anim(center("You are in a dark room. Moonlight shines through the window.\n"), 50);
  anim(center("There is GOLD in the corner, along with a SHOVEL and a ROPE.\n"), 100);
  anim(center("There is a DOOR to the EAST.\n"), 25);
  std::cout<<"Command?\n";
  while(1) {
    in="";
    std::cout<<"> ";
    std::getline(std::cin, in);
    std::cin.clear();
    if(in == "OPEN DOOR")
      d |= 0x01;
    else if(in == "GO EAST")
      if (d & 0x01)
        break;
      else
        anim("...\n", 1000);
    else if(in == "PICK UP ROPE")
      d |= 0x40;
    else if(in == "PICK UP GOLD")
      if(d & 0x40){
        d |= 0x20;
      }else{
        std::cout<<"Glistening gold, too high to reach.\n";
      }
    else if(in == "PICK UP SHOVEL")
      d |= 0x10;
    else
      std::cout<<"Invalid Command.\n";
  }
  
  //s2
  d &= 0xF8;
  clear();
  while(1){
    anim(center("Reap your reward.\n"), 50);
    if(d & 0x20)
      anim(center("PALE LUNA SMILES AT YOU.\n"), 200);
    anim("You are in a forest. There are paths to the NORTH,", 50);
    if ((d & 0x07) != 0) 
      anim(" SOUTH,", 50);
    anim(" WEST, and EAST.\n", 50);
    std::cout<<"Command?\n";
    in="";
    std::cout<<"> ";
    std::getline(std::cin, in);
    std::cin.clear();
    if(in == "GO NORTH")
      if((d & 0x07) == 0 || (d & 0x07) == 4){
        d+=1;
        clear();
      }else
        c();
    else if(in == "GO EAST")
      if((d & 0x07) == 1 || (d & 0x07) == 3){
        d+=1;
        clear();
      }else
        c();
    else if(in == "GO SOUTH")
      if((d & 0x07) == 2){
        d+=1;
        clear();
      }else if((d & 0x07) == 7)
        break;
      else
        c();
    else if(in == "GO WEST")
      if((d & 0x07) == 5 || (d & 0x07) == 6){
        d+=1;
        clear();
      }else
        c();
    else if(in == "USE GOLD" && (d & 0x20)){
      clear();
      anim("Not here.\n", 50);
    }else if(in == "USE SHOVEL" && (d & 0x10)){
      clear();
      anim("Not now.\n", 50);
    }else if(in == "USE ROPE" && (d & 0x40)){
      clear();
      anim("You've already used this.\n", 200);
    }else{
      clear();
      std::cout<<"Invalid Command.\n";
    }
  }

  //s3
  d &= 0xF8;
  clear();
  while(1){
    anim(center("PALE LUNA SMILES WIDE.\n"), 200);
    anim(center("There are no paths.\n"), 50);
    anim(center("PALE LUNA SMILES WIDE.\n"), 200);
    anim(center("The ground is soft.\n"), 50);
    anim(center("PALE LUNA SMILES WIDE.\n"), 200);
    anim(center("Here.\n"), 250);
    std::cout<<"Command?\n";
    in="";
    std::cout<<"> ";
    std::getline(std::cin, in);
    std::cin.clear();
    if(in == "DIG HOLE" && (d & 0x07) == 0)
      if(d & 0x10){
        d+=1;
        clear();
      }else{
        clear();
        std::cout<<"You can't.\n";
      }
    else if(in == "DROP GOLD" && (d & 0x07) == 1)
      if(d & 0x20){
        d+=1;
        clear();
      }else{
        clear();
        std::cout<<"Where is she?\n";
      }
    else if(in == "FILL HOLE" && (d & 0x07) == 2)
      break;
    else
      c();
  }
  
  clear();
  anim(center("Congratulations.\n"), 66);
  anim(center("—— 40.24248 ——\n"), 100);
  anim(center("—— -121.4434 ——\n"), 100);

  return 0;
}
