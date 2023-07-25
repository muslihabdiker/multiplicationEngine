#include <iostream>
#include <fstream>
#include "string.h"
#define OPEN int main(){
#define CLOSE }
#define r return
#define z 0
#define ST  using namespace std;
#define maximum 1000
#define x 10
#define y 20
#define k 10001
#define l 10001
#define out_x 30000
#define out_y 30000
ST
//variables
int** output_matrix = new int* [out_x];
int pgErr;
int sizeN1;
int sizeN2;
int output_size;
int MainCounter;
int LayerCounter = 0;
int overflow = 0; 
int result = 0;
int vram_sumArray[10];
int vram_counter;

long long unsigned int vram_overflowArray;
long long unsigned int vram_temp_result_holder;
///classes
//multiplication reference class
class multiplication_reference {
    public:
int** mat = new int* [x];
// allocate memory for y values
void query(int n1,int n2,int i,int j) {
    for(int i=0; i<x; i++) {
    mat[i] =  new int[y];
    }

    // assign values for the allocated memory
    for(int i=0; i<x; i++) {
        for(int j=0; j<y;) {
            mat[i][j] = (i*(j/2))/10;//overflow
            mat[i][j+1] = (i*((j/2)))%10;//number
            j = j+2;
        }
    }

//post queried values to the processor
processor(mat[n1][n2*2],mat[n1][(n2*2)+1],i,j);
}
//function processor
void processor(int OV,int N,int i,int j) {
    //obejects
    int tempResult;
    int tempOverflow;
// //early developement phase
// std::cout<<"i: "<<i<<std::endl;//ov
// std::cout<<"j: "<<j<<std::endl;//ov

// std::cout<<"ov: "<<OV<<std::endl;//ov
// std::cout<<"n: "<<N<<std::endl;//n
// std::cout<<N<<std::endl;
//check end of layer 
if(MainCounter ==0){
        // MainCounter = 1;
// std::cout<<"called :  index: "<<j<<"\n";
tempResult =N + overflow;
result = (OV*10)+tempResult;
// std::cout<<"res: "<<result<<std::endl;
    overflow =0;

}else {
    // add previous overflow
tempResult = (N + overflow)%10;
//new overflow
int nv = (N+overflow)/10;
tempOverflow = OV+nv;
// std::cout<<"tempov: "<<tempOverflow<<" \n";
// store new overflow
    /// set overflow to zero
    overflow =0;
overflow = tempOverflow;
// std::cout<<"over: "<<overflow<<std::endl;
result = tempResult;
tempResult =0;
tempOverflow =0;
// std::cout<<"res: "<<result<<std::endl;
}

}
};

//number store declaration
class number_store_array {
public:
//temporary arrays
int tn1[maximum];
int tn2[maximum];
int cn1 = 0;
int cn2 = 0;
std::string sn1;
std::string sn2;
int isn1;
int isn2;

int  number_stream(){
std::fstream fn1;
std::fstream fn2;
std::fstream sfn1;
std::fstream sfn2;
fn1.open("n1.dat");
fn2.open("n2.dat");
sfn1.open("sn1.dat");
sfn2.open("sn2.dat");
//read size frrom file
///sn1 size stored in file
while(getline(sfn1,sn1)) {
isn1 = stoi(sn1);
sizeN1 = isn1;
}
///sn2 size stored in file
while(getline(sfn2,sn2)) {
isn2 = stoi(sn2);
sizeN2 = isn2;
}
//assign tn1
while(isn1 != 0) {
fn1>>tn1[cn1];
cn1++;
isn1--;
}
//assign tn2
while(isn2 != 0) {
fn2>>tn2[cn2];
cn2++;
isn2--;
}

r z;
}

};
// vram implimentation class
class vram {
public:
int** vram_pointer = new int* [k];

void vram_func() {
//memory allocation
for(int i=0; i<k; i++) {
vram_pointer[i] = new int[l];
}
//value assignment  
   ///loop method
// for(int i=0; i<k; i++) {
//  for(int j=0; i<l; j++) {
//   vram_pointer[k][l] = input;
//  }
// }
 //direct insertion(faster version) 
 
 }
///compute sum
//vram sum function
 void add_vram() {
    // calculate occupied vram layers

    //memory allocation for vram outputs
for(int i=0; i<out_x; i++) {
    output_matrix[i] = new int[out_y];
}
  // loop log 
  int loopLog = 10001;
for(int i=0; i<loopLog;i++) {
    for(int j=0; j<loopLog; j++) {
        // if(untouchable_sizeN2 !=0){
      //process sum and put in vram teemporary result holder
      //operation
   vram_temp_result_holder = vram_pointer[i][loopLog]+vram_pointer[i+1][loopLog]+vram_temp_result_holder;
   /// processor
   // add previous overflow
   vram_temp_result_holder = vram_temp_result_holder+vram_overflowArray;
//    std::cout<<"row addition: "<<i<<" "<<j<<" "<<vram_temp_result_holder;
           //create overflow
           vram_overflowArray = vram_temp_result_holder/10;
//output
 output_matrix[i][j] = vram_temp_result_holder%10;
 //  clear variables
 vram_temp_result_holder = 0;
//      }else {
// break;
     }
         ///position logger
       loopLog--;
    //    untouchable_sizeN2--;
}
// }
//print result
// std::cout<<output_matrix[0][3];
// std::cout<<"results: \n";
// for(int i=0; i<LayerCounter; i++) {
//     for(int j=0; j<out_y; j++)  {
//         std::cout<<output_matrix[i][j];
//     }
//     LayerCounter--;
// }
// std::cout<<"layers: "<<LayerCounter<<std::endl;
}
};

//start of main function



//  -----------------                   ////
OPEN
//variables
int positionLog = 10000;
//objects
multiplication_reference MR;
number_store_array NSA; 
vram vrm;
//read n1 and n2
NSA.number_stream();
       std::cout<<"size n1: "<<sizeN1<<std::endl;
                std::cout<<"size n2: "<<sizeN2<<std::endl;
                //print n1 
                // for(int i=0; i<sizeN1;i++) {
                //     std::cout<<"n1: i: "<<" "<<i<<" "<<NSA.tn1[i]<<std::endl;
                // }
                //allocate memory for vram
                vrm.vram_func();
//operation loop 
//layers count for vram
///  number read error --- operation loop error
// number operation should start from far right
for(int i=sizeN1-1; i>=0;i--) {

    for(int j=sizeN2-1; j>=0; j--) {
                   MainCounter =j;

     MR.query(NSA.tn1[i],NSA.tn2[j],i,j); 
       //store operation result
   //assign values to vram
//    std::cout<<"i: "<<NSA.tn1[i]<<"j: "<<NSA.tn2[j]<<std::endl;
     vrm.vram_pointer[i][positionLog-j]  = result;
    //  std::cout<<"Res "<<result<<"\n";
    // std::cout<<"layer1 pos 0 10001 "<<vrm.vram_pointer[0][9998]<<"\n";

     }
    // layer count increase
     ///no need for LayerCounter implimentation , i variable will be used automatically as layer counter
    // LayerCounter++;
         ///position logger
    //    positionLog--;
       LayerCounter++;
}
//print layers
std::cout<<"Layers: "<<LayerCounter<<"\n";
/// vram addition function
vrm.add_vram();
//vram pointer print
//layer values
  
int printLog =10001;

for(int i=0; i<sizeN1;i++) {
    for(int j=0; j<sizeN1; j++) {
   std::cout<<vrm.vram_pointer[i][positionLog-j]<<" ";
     }
    printLog--;
}

r z;
CLOSE
// end of main function