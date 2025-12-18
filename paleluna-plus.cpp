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

//kitty
#ifdef _WIN32
  #include <conio.h>
#else
  #include <termios.h>
  #include <unistd.h>
#endif

const std::string& b64_Treasure = "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";

const std::string& b64_Nevins = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAhDEnFx6kAAAImSURBVFjDvVehUsNAEN3LZEJjIuKpZFAILLY1FZj+QU1tpwZRHYFhamOwqBpEDfwAhgEUuviKmjAxQWQ22dvuXS4t6Zomucu+zdvdd1sVTqEI+wFwyzY58OfbRQ4uFieB+L6EoeIkKGybXEFtwdgC8LsC5n5MgfhSVKeysB+Al21yDbQpb4cax0HzJMCugpD8el0Cuph3ynxLqfBd+hUAYD0ba/ej5arVOg0EA9B0INvkcPFxBQAAP7ffWhty565Gg6BtiB9t1QHJHh5fquv5ZOi8ZkpH2A9qBs6fL7VNn29f/1oDzkJkyv1ouYKiqFVbKeW8dlQXUGopgMsz6V3nACTKlFIVEC1MvKbrrgeSipOgwLa4eYoAAOD97lc7TI7pAgkc8cJ+UNYA7U1bGmh1c3ptaxyU/vou+v+625UXJBCp1RC42m8QoL0U4M31fU9LgW0mGESRHGTLocQ/dBixAbYZSpyVkPd5+z0FbBfIyJl+GAEAZCkARL29FkMhoQ4pUJMW1IKkM4JsqHAKRZbKB06TirmayXeckLNAyjuO11laf7WJfs6OUkp731SY1i6QCslEP0+DqfL5/OHrk3BPnIzpFzQxQAMOp80zoVUJERh73rX1qv1puR8DkaYv42GUpaWj9WxcqR4XHxv4fDKE9WwMgyjSGOQfqtUAXcQATCLE6W2zf68G2qodB8dnSHkbMzLQ5XhOT0ZP2kApOvZPC/rjfvD+DwxlOnR5ur2eAAAAAElFTkSuQmCC";

const std::string& b64_Grass = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAiEpjnqQkAAAEESURBVFjDxZcxEsMgDATlKzzjNg/I9/ySfDSfyEwaUjkFY6Q7KTGUWAtIHJK8bLu17b5aP17Pt53N9zZmZhUeI6MIjuxYHtEJDy8zg+ERQZ4no9ArPFhg5E2VP9XAMdd/82yzPBTBqEIsiXAUWlaYLA9vsSjk0WEYHqpnowWz/HJ7rI3NXFHIMzyyz4cVYsTjnwpneNjkASZkShRUHmr+PrOv8HQm9Dap8IjyN7tJlv/mAbXjYfVAaSBbz9Wrog5wdWVctt1aBHpplgmzx8/vB5g361W8Ki/VgoynEY+r2m/3Ffy6y1F4zCjBdCa8vBx74WPuOcMj87PpbaTyyCpb7RlG/AfBRii0V2E2uQAAAABJRU5ErkJggg==";

const std::string& b64_Edge = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAiCGWFUHMAAAGLSURBVFjDtVc7TgNBDDVWtNLWlJG2TIVQTsIBuADX2NNwnihKgVKCUlIjISSoZjUx/jx7YZqssvNm/Hl+9t6MT/Q9TgPJ9fH6Sdr/cg8R0TgNyzMR0e5wT+f9EcKztSkCy33tdz5tFyOQxZGFvWdINLJ4jkBeJPp3lUiO00CbPo9aPrV8e57PdxciuvxKgYVXOSDz6nmj7W2XI3jOEM4LpYzEeX9cR0KLCxaxZBVIoyw8eyz1Qi4Pk+dYOiLxHHmG6oBcJR1AysojaauCx807LF4cXYhGporn6sGWTsynLT1/3dLbwwuEZ/qjFQlUWYrRKGSr6cqAjP5r+/vnRkKvCno8Zzy0jFyDZ6S0kEuq77litTVB9VWA4lfNA56H5TKsdsYlAoASXhnglV3fJ6I0aTqA4P9tHoCbEVLzXsfUpuJGQgSf6gWesVaYIzyvmQWyug9xIDImmnKy5cprWrC2Whk2HYC7YSTFsAGChKl27IU/mxptSNXwsBJGPIl0wMJz9cPU+urppRjB/wC+uVI9ZkJlNgAAAABJRU5ErkJggg==";

const std::string& b64_Tree = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAhO/F4YqYAAAHRSURBVFjDtVc7TsQwEJ1YxlIKUoQWBYE4yl6CE+QKoK1ziByIO1DQkIZqt6CxlGYp0EReZ35OxEirlZxM5s34zfO4qnu41F2A3OI0A7We2vk4AwBAO2zzj9MMjnvJErwdArRDWICU+KM5DWGcZjY4GgeC8xcB5E7WTBBEiX/dBXBWB3wvzz63h8fnomqSHMC1/FkcQQzeDgE+Xj9ZfyqWs5ZZC74wvweSD5x56WMITit7voUR5iv/9D9fdxJLLcHxPfzhVsSRrmy6dqUDFEkswbWu0Kxqh3ChlEtyLgGlJeE5hqLT+fhHrD0mybIv+ZClW0o6QAVg4UAeMK0Wtq5EdC+1n6kqPV+pCDPcujuA7iQD4Hp277a0Q4Cvt+9VFdN4rBKW7uXWQ8pJ+r9VA7hK3d888TpgyZ6bfCzbwRF6BUDq+zjKldHAUCC8BeVCmn4bIaU2XA0k3HyXHzglKigd5xU1Fe85hKiMpVmCJCFVCQugNDDyJfWlRM5bTzzqDkBlKgGuu7Use4v84qilCdShaeD95adI0n2OLHfMER+aZhMfOJl3Ujtpl4o9xFwB4IbH/zZXepWSDPe/pArOeilJg2iBNJVME/Wle2bNVpNnXP8F5WBJWozyQIYAAAAASUVORK5CYII=";

const std::string& b64_Spark = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAhLQWs1/cAAAFJSURBVFjDxZYxDsIwDEVdCxWVEXauB2dghzNwvu5dQbCUqRBMHH87Fc3Sqs2L7eTbcdMdaOz2Lclx75+U+y7nEBHV8KxNsmBrHsqz5eEUZWQgPFtQKRJt6z08o4AWTS2f1cD0Tf4rzY3y7BGMV4hVItS2FhUmynNpMWvLh9ODavivOhBNudt1rOJZ886bfhG+27cfB7zpgzpl8RxdeDg9su/eDGFaeDTbczuiN5yMdndZ/0S/OTau2rDKGZWpVhq7y5ru/fOdDdNz+mdd42Yl1BZJv6dGtd3SCtPPEVjVTRqTx6A5nDYpabNSdKCkB3k0OcOWnqr7Ac8dADuAGkwjTt+9DnOuUslssCphDb98P4C0ztqNWVI8wrvTEO33PTz/q/2GNWAthnQ5Hp7nFpWXd2tg7sHoWSLnHOE50u+VDHl5jiobqR8I/wKWwkJM9/VzxgAAAABJRU5ErkJggg==";

const std::string& b64_Ledge = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAvKZxCPmAAAAFzSURBVFjDvVe9TsQwDP5qVafr0gGJFXXtAtItDKy8BE9wj8ATMNyT8CSsrKyItRsLiOWYcnJCHNtpDi9tUn/x5x/VTjfscRyuNkjl6+MHuf1UBwDW4ElS0sCanhVPGsPgZY1Y8KSBSp5IoffgyQqQvFmLz9ZA2Eu/lXRr8eQpGG8hripCKbTWwrTiqXSYFnKNjAVPXs+kA2vx3cXT5ogGYvnzZQncj+OJwOvjN/5TdodtXIS7w/b0DO+tDXIbANDd3F5HKbh8ewePSI5Iul9aS2cAwDJPcQokWeYpS7CF9BalklFOzor5QyA9RAIHPf5d09XImFJwTumXeWqeVy0afJ2NACeVC7ulFqxOmVNQa0AlMOwREbh7HpuEukTy5eEzJsAbiiRriOWMB5tqMwpNRiJnIcY9Tluyuxvyrudtv8ERTqDXLhjWWaB2NKNzTDkePLUeMr34ZhNRk6m4FD7LzFeDp5rLZsmQF0+1F0vL1duC/wVOMyASvqGFagAAAABJRU5ErkJggg==";

const std::string& b64_Steps = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAzBD/qP0gAAAGgSURBVFjDvVcxbsMwDKQJI3AWDwWyFl69tEaWDl3zCb+gT+gLOuQlfYnXDl4CeAqyesuSwksyyaBlUSJlt9xs8aQjdaKoZPsB9+3zBmy7XQZw/bd9AACW4JFzCoFDflI8hhiaKGNMgscQyBcJl3oNHqUALpqleKcGzD97zOcbi0eNYLRCXCRCLrVSYUrx6JsslPIQGQketZFxE8bik6evzR1WMEnlcxI45PlI4OfzF/7T9sdsSsCQ2B8zAABo6uuqJ8PMS9dIXt9eJgR2p/OETGwpfv/OZ4vZ1pfFPAOco4sgZ019HQmoNBBjlByXSZ+lrkk4sNHE9Cy3zmilWUs5B3oibpdhXGS+WLYsA31ZOJ2pcJp6CO65XZQoWTsb9NupAUrKOIcisrexq1qREMUi7MsCuqqdRSpVO7sFdrHhJtydztBV03F7a7RiBgBIaFfsKzpLI+X0EryMzCXDkZMQs7NMj7H6NqS3nrZMm0AogTT0wJD2ArGtGf5Fl6PB49pNpha/Wke0SlfsS5+k54vBY8xj07eQFo+xD0vJ01uCfwB9iUELuDP94QAAAABJRU5ErkJggg==";

void img(){
  std::cout<<"\n";
  for(int i = 0; i < w.ws_col/4; ++i)
    std::cout<<" ";
  std::cout
    << "\033_G"
    << "a=T,f=100,c=" << w.ws_col/2 << ",r=" << w.ws_row/2 <<";"
    << b64_Treasure
    << "\033\\"
    "\n";
}

void sprite(std::string b64) {
  std::cout
    << "\033_G"
    << "a=T,f=100,c=2,r=1;"
    << b64
    << "\033\\";
}

char getChar() {
#ifdef _WIN32
    return _getch();
#else
    termios oldt, newt;
    char c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    read(STDIN_FILENO, &c, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
#endif
}

struct MapData{
  char elements[8][16];
};

struct MapData Maps[6] = {
  {
    //--0-DATA--------
    //    e          t
    //    e          t
    //    e          t
    //    e          t
    // +  e          t
    //   e           t
    //  e            t
    // e             t
    {
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', '+', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'}
    }
  },{
    //--1-DATA--------
    //t              t
    //t     tt       t
    //t      t       t
    //t              t
    //t              t
    //t
    //t      tt
    //t      tt
    {
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', 't', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', 't', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', 't', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    }
  },{
    //--2-DATA--------
    //t
    //t
    //t
    //t
    //t
    //          tttttt
    //
    //
    {
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 't', 't', 't', 't', 't'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    }
  },{
    //--3-DATA--------
    //
    //
    //     |||||||||||
    //    e
    //    et
    //    e          t
    //    e          t
    //    e          t
    {
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', 'e', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'}
    }
  },{
    //--4-DATA--------
    //
    //               t
    //|||||||t|||||||t
    //       t       t
    //       tt      t
    //t              t
    //t      t       t
    //t   t          t
    {
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'|', '|', '|', '|', '|', '|', '|', 't', '|', '|', '|', '|', '|', '|', '|', 't'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 't', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'}
    }
  },{
    //--5-DATA--------
    //
    //t
    //t|||||cccc||||||
    //t
    //t
    //t
    //t
    //t
    {
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', '|', '|', '|', '|', '|', 'c', 'c', 'c', 'c', '|', '|', '|', '|', '|', '|'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    }
  }
};

int player_y=7, player_x=10;

void render(){
  clear();
  for(int row = 0; row < 8; ++row){
    for(int col = 0; col < 16; ++col){
      if(row==player_y && col==player_x)
        sprite(b64_Nevins);
      else{
        switch(Maps[d & 0x07].elements[row][col]){
          case ' ':
            sprite(b64_Grass); //grass
            break;
          case 't':
            sprite(b64_Tree); //tree
            break;
          case 'e':
            sprite(b64_Edge); //edge
            break;
          case '|':
            sprite(b64_Ledge); //slope
            break;
          case 'c':
            sprite(b64_Steps); //slope with steps
            break;
          case '+':
            if(d & 0x08)
              sprite(b64_Spark); //grass with sparkle
            else
              sprite(b64_Grass);
            break;
          default:
            std::cout<<"E"; //error
            break;
        }
      }
    }
    std::cout<<"\n";
  }
}
bool checkPos(int x, int y){
  char c = Maps[d & 0x07].elements[player_y + y][player_x + x];
  return c == ' ' || c == 'c' || c == '+';
}
void movePlayer(char move){
  switch(move){
    case 'w':
    case 'W':
      if(player_y > 0){
        if(checkPos(0, -1))
          --player_y;
      }else if((d & 0x07) < 3){
        d+=3;
        player_y+=7;
      }
      break;
    case 's':
    case 'S':
      if(player_y < 7){
        if(checkPos(0, 1))
          ++player_y;
      }else if((d & 0x07) >= 3){
        d-=3;
        player_y-=7;
      }
      break;
    case 'a':
    case 'A':
      if(player_x > 0){
        if(checkPos(-1, 0))
          --player_x;
      }else if((d & 0x07) % 3 != 0){
        if((d & 0x07) == 4)
          d|=0x08;
        d-=1;
        player_x+=15;
      }
      break;
    case 'd':
    case 'D':
      if(player_x < 15){
        if(checkPos(1, 0))
          ++player_x;
      }else if((d & 0x07) % 3 != 2){
        if((d & 0x07) == 3)
          d&=0xF7;
        d+=1;
        player_x-=15;
      }
      break;
  }
}
void extra();
//kitty

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

  //kitty only
  extra();
  clear();
  img();
  return 0;
}

void extra(){
  d=0;  //ABCD EFGH
        //FGH = screen 3 4 5
        //             0 1 2
        //E   = flag to check if coming to 0 via 3,
        //      turns off with 4. used for gold sparkle
        //A   = flag to end game
  clear();
  do{
    render();
    movePlayer(getChar());
    if(Maps[d & 0x07].elements[player_y][player_x] == '+')
      break;
  }while(1);
}
