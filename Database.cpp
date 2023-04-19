#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <numeric>
#include <fstream>


using namespace std;
namespace S_tables{
    struct S1{
        int col_one;
        int col_two;
        int col_three;
    };
    struct S2{
        int col_one;
        int col_two;
        int col_three;
    };
    struct S3{
        int col_one;
        int col_two;
        int col_three;
    };
}
struct P{
    int id;
    string name;
    int age;
};

struct I{
    int id;
    string food;
    int amount;
};





//print tables
void printTable(vector<string> cols,string tablename){
    cout<<"_______________________________________"<<endl;
    cout<<tablename<<endl;
    cout<<"_______________________________________"<<endl;
    for(int y=0;y<cols.size();y++){
        cout<<left<<setw(12)<<cols[y];
    }
    cout<<endl;
}
int main(){
    //P table
    P data[11];

    srand(time(nullptr));
    vector <string> name_one;
    for(int i=1;i<11;i++){
        data[i].id = i;
        int textLength = rand()% 5+6;
        string randomText="";
        for(int j=0;j<textLength;j++){
            char letter =  rand() % 26 + 'a';
            randomText += letter;
        }
        data[i].name = randomText;
        data[i].age = rand() % 11+20;
    }
    vector<string> v1={"customer id","name","age"};
    printTable(v1,"P");
    cout<<endl;

    for(int i=1;i<11;i++){
        cout<<left<<setw(12)<<data[i].id<<setw(12)<<data[i].name<<setw(12)<<data[i].age<<setw(12)<<endl;
    }
    cout<<endl<<endl;
    ////////////
    //S tables//
    ////////////

    //S1 table
    S_tables::S1 tableOne[11];
    for(int k=1;k<11;k++){
        tableOne[k].col_one = k;
        tableOne[k].col_two = 1 + rand() % 10;
        tableOne[k].col_three = 1 + rand() % 10;
    }
    vector<string> v2={"id","customer id","item id"};
    printTable(v2,"s1");
    cout<<endl;
    for(int i=1;i<11;i++){
        cout<<left<<setw(12)<<tableOne[i].col_one<<setw(12)<<tableOne[i].col_two<<setw(12)<<tableOne[i].col_three<<setw(12)<<endl;
    }
    cout<<endl<<endl;

    //S2 table
    S_tables::S2 tableTwo[11];
    for(int k=1;k<11;k++){
        tableTwo[k].col_one = k;
        tableTwo[k].col_two = 1 + rand() % 10;
        tableTwo[k].col_three = 1 + rand() % 10;
    }
    vector<string> v3={"id","customer id","item id"};
    printTable(v3,"s2");
    cout<<endl;
    for(int i=1;i<11;i++){
        cout<<left<<setw(12)<<tableTwo[i].col_one<<setw(12)<<tableTwo[i].col_two<<setw(12)<<tableTwo[i].col_three<<setw(12)<<endl;
    }
    cout<<endl<<endl;

    //S3 table
    S_tables::S3 tableThree[11];
    for(int k=1;k<11;k++){
        tableThree[k].col_one = k;
        tableThree[k].col_two = 1 + rand() % 10;
        tableThree[k].col_three = 1 + rand() % 10;
    }
    vector<string> v4={"id","customer id","item id"};
    printTable(v4,"s3");
    cout<<endl;
    for(int i=1;i<11;i++){
        cout<<left<<setw(12)<<tableThree[i].col_one<<setw(12)<<tableThree[i].col_two<<setw(12)<<tableThree[i].col_three<<setw(12)<<endl;
    }
    cout<<endl<<endl;

    ////////////
    //I table//
    ////////////

    string food_stuff_array[] = {"Milk","Sugar","Apple","Honey","Cheese","Butter","Oil","Flour","Potato","Onion"};
    int counter = 0;
    I food_stuff[11];
    for(int b=1;b<11;b++){
        food_stuff[b].id = b;
        food_stuff[b].amount = 1 + rand() % 100;
        food_stuff[b].food = food_stuff_array[counter];
        counter++;
    }
    vector<string> i={"item id","food","amount"};

    printTable(i,"I");
    cout<<endl;
    for(int i=1;i<11;i++){
        //cout<<left<<setw(12)<<food_stuff[i].id<<setw(12)<<food_stuff[i].food<<setw(12)<<endl;
        cout<<left<<setw(12)<<food_stuff[i].id<<setw(12)<<food_stuff[i].food<<"GHc"<<" "<<food_stuff[i].amount<<".00"<<setw(12)<<endl;
    }
    cout<<endl<<endl;




    //How much each person spends in each shop

    int temp;
    int start = 1;
    vector<int> total_display;
    vector<int> total_display1;
    vector<int> total_display2;
    while(start < 11){
    vector<int> indices;
    vector<int> indices1;
    vector<int> indices2;
    //the number of product person one buys
    for(int a=1;a<11;a++){
        if(tableOne[a].col_two == start){

           indices.push_back(a);
        };
        if(tableTwo[a].col_two == start){

           indices1.push_back(a);
        };
        if(tableThree[a].col_two == start){

           indices2.push_back(a);
        };
    }

    cout<<endl;
    vector<int> product;
    vector<int> product1;
    vector<int> product2;
    //find the product id(s)

    for(int i=0;i<indices.size();i++){
        product.push_back(tableOne[indices[i]].col_three);
    }
    //for(int c=0;c<product.size();c++){
      //  cout<<indices[c]<<" "<<c<<"products: "<<tableOne[indices[c]].col_three<<endl;
    //}

     for(int i=0;i<indices1.size();i++){
        product1.push_back(tableTwo[indices1[i]].col_three);
    }
    for(int i=0;i<indices2.size();i++){
        product2.push_back(tableThree[indices2[i]].col_three);
    }
    //search items table
    //but first search the index table and grab the index of the products
    vector<int> f_cost;
    vector<int> f_cost1;
    vector<int> f_cost2;
    for(int a=0;a<product.size();a++){
        f_cost.push_back(food_stuff[product[a]].amount);
    }
    for(int a=0;a<product1.size();a++){
        f_cost1.push_back(food_stuff[product1[a]].amount);
    }
    for(int a=0;a<product2.size();a++){
        f_cost2.push_back(food_stuff[product2[a]].amount);
    }
    int sum = accumulate(f_cost.begin(), f_cost.end(), 0);
    int sum1 = accumulate(f_cost1.begin(), f_cost1.end(), 0);
    int sum2 = accumulate(f_cost2.begin(), f_cost2.end(), 0);
    total_display.push_back(sum);
    total_display1.push_back(sum1);
    total_display2.push_back(sum2);






    start++;
    }
    cout<<"total amount for each individual in shop one"<<endl;
    cout<<"customer id"<<"  "<<"amount spent"<<endl;
    for(int c=0;c<total_display.size();c++){
        if(total_display[c]>0){
            cout<<c+1<<"            "<<"Ghc "<<total_display[c]<<".00"<<endl;
        }
    }

    cout<<endl;
    cout<<"total amount for each individual in shop two"<<endl;
    cout<<" customer id"<<"  "<<"amount spent"<<endl;
    for(int c=0;c<total_display1.size();c++){
        if(total_display1[c]>0){
            cout<<c+1<<"            "<<"Ghc "<<total_display1[c]<<".00"<<endl;
        }
    }
    cout<<endl;
    cout<<"total amount for each individual in shop three"<<endl;
    cout<<"customer id"<<"  "<<"amount spent"<<endl;
    for(int c=0;c<total_display2.size();c++){
        if(total_display2[c]>0){
            cout<<c+1<<"            "<<"Ghc "<<total_display2[c]<<".00"<<endl;
        }
    }
    cout<<endl;
    cout<<"total amount for each individual in all shops"<<endl;
    cout<<"customer id"<<"  "<<"amount spent"<<endl;
    int total_sale[10];
    for (int i = 0; i < 10; i++) {
        total_sale[i] = total_display[i] + total_display1[i] + total_display2[i];
        if(total_sale[i]>0){
            cout<<i+1<<"            "<<"Ghs "<<total_sale[i]<<".00"<<endl;
        }
    }
    cout<<endl;
    int beginn= 0;

    int f=0;
    vector<int> t_sales;
    vector<int> t_sales1;
    vector<int> t_sales2;
    cout<<"Sales per item in shop one"<<endl;
    cout<<"item id"<<"        "<<"sales"<<endl;


    for(int b=1;b<11;b++){
    int counts=0;
    int counts1=0;
    int counts2=0;
        for(int j=1;j<11;j++){
            if(food_stuff[b].id == tableOne[j].col_three){
                counts++;
            }
            if(food_stuff[b].id == tableTwo[j].col_three){
                counts1++;
            }
            if(food_stuff[b].id == tableThree[j].col_three){
                counts2++;
            }
        }
    t_sales.push_back(counts);
    t_sales1.push_back(counts1);
    t_sales2.push_back(counts2);
    }

    int ss =1;
    int ss1 =1;
    int ss2 =1;
    int total_p[10];
    int total_p1[10];
    int total_p2[10];
    for (int i = 0; i < 10; i++) {
        total_p[i] = food_stuff[ss].amount * t_sales[i];
        ss++;
        if(total_p[i]>0){
          cout<<i+1<<"            "<<"Ghs "<<total_p[i]<<".00"<<endl;
        }
    }
    cout<<endl;
    cout<<"Sales per item in shop two"<<endl;
    cout<<"item id"<<"        "<<"sales"<<endl;
    for (int i = 0; i < 10; i++) {
        total_p1[i] = food_stuff[ss1].amount * t_sales1[i];
        ss1++;
        if(total_p1[i]>0){
          cout<<i+1<<"            "<<"Ghs "<<total_p1[i]<<".00"<<endl;
        }
    }
    cout<<endl;
    cout<<"Sales per item in shop three"<<endl;
    cout<<"item id"<<"        "<<"sales"<<endl;
    for (int i = 0; i < 10; i++) {
        total_p2[i] = food_stuff[ss2].amount * t_sales2[i];
        ss2++;
        if(total_p2[i]>0){
          cout<<i+1<<"            "<<"Ghs "<<total_p2[i]<<".00"<<endl;
        }
    }


    cout<<endl;
    cout<<"total sales in shop one"<<endl;
    int n = sizeof(total_p)/sizeof(total_p[0]);
    int summ = accumulate(total_p, total_p + n, 0);
    cout<<"GHc "<<summ<<".00"<<endl<<endl;

    cout<<"total sales in shop two"<<endl;
    int n2 = sizeof(total_p1)/sizeof(total_p1[0]);
    int summ1 = accumulate(total_p1, total_p1 + n, 0);
    cout<<"GHc "<<summ1<<".00"<<endl<<endl;

    cout<<"total sales in shop three"<<endl;
    int n3 = sizeof(total_p2)/sizeof(total_p2[0]);
    int summ2 = accumulate(total_p2, total_p2 + n3, 0);
    cout<<"GHc "<<summ2<<".00"<<endl;
    cout<<endl<<endl;
    //ploting 11*11 table that output  1(if a user has bought an item from a particular ship) and 0 of the customer has not bought any item from the shop
    //peopleid ->colums and items->rows
    //S1 table
    cout<<"SI plot table for people and items"<<endl<<endl;
    vector<int> index;
    int b_start=1;
    int beg=1;
      int p_arr[11][11]={0};
    while(b_start<11){
    for(int a=1;a<11;a++){
        if(tableOne[a].col_two == b_start){
            index.push_back(a);

        };

    }

    vector<int> product_dis;
    for(int i=0;i<index.size();i++){
        product_dis.push_back(tableOne[index[i]].col_three);
    }
    //for(int v=0;v<product_dis.size();v++){
      //  cout<<product_dis[v];
    //}
    //cout<<endl;


    for(int y=0;y<11;y++){
        p_arr[0][y]=y;
    }
    for(int y=1;y<=11;y++){
        p_arr[y][0]=y;
    }


    for(int i=0;i<product_dis.size();i++){

    p_arr[beg][(product_dis[i])]=1;

    }
    index.clear();

    b_start++;
    beg++;


}
for(int l=0;l<11;l++){
    for(int p=0;p<11;p++){
        cout<<setw(5)<<p_arr[l][p]<<setw(2);
    }
    cout<<endl;
    }


cout<<endl<<endl;
 //S2 table
    cout<<"S2 plot table for people and items"<<endl<<endl;
    vector<int> index2;
    int b_start2=1;
    int beg2=1;
      int p_arr2[11][11]={0};
    while(b_start2<11){
    for(int a=1;a<11;a++){
        if(tableTwo[a].col_two == b_start2){
            index2.push_back(a);

        };

    }

    vector<int> product_dis2;
    for(int i=0;i<index2.size();i++){
        product_dis2.push_back(tableTwo[index2[i]].col_three);
    }
    //for(int v=0;v<product_dis.size();v++){
      //  cout<<product_dis[v];
    //}
    //cout<<endl;


    for(int y=0;y<11;y++){
        p_arr2[0][y]=y;
    }
    for(int y=1;y<=11;y++){
        p_arr2[y][0]=y;
    }


    for(int i=0;i<product_dis2.size();i++){

    p_arr2[beg2][(product_dis2[i])]=1;

    }
    index2.clear();

    b_start2++;
    beg2++;


}


    for(int l=0;l<11;l++){
    for(int p=0;p<11;p++){
        cout<<setw(5)<<p_arr2[l][p]<<setw(2);
    }
    cout<<endl;
    }




    cout<<endl<<endl;
 //S3 table
    cout<<"S3 plot table for people and items"<<endl<<endl;
    vector<int> index3;
    int b_start3=1;
    int beg3=1;
      int p_arr3[11][11]={0};
    while(b_start3<11){
    for(int a=1;a<11;a++){
        if(tableThree[a].col_two == b_start3){
            index3.push_back(a);

        };

    }

    vector<int> product_dis3;
    for(int i=0;i<index3.size();i++){
        product_dis3.push_back(tableThree[index3[i]].col_three);
    }
    //for(int v=0;v<product_dis.size();v++){
      //  cout<<product_dis[v];
    //}
    //cout<<endl;


    for(int y=0;y<11;y++){
        p_arr3[0][y]=y;
    }
    for(int y=1;y<=11;y++){
        p_arr3[y][0]=y;
    }


    for(int i=0;i<product_dis3.size();i++){

    p_arr3[beg3][(product_dis3[i])]=1;

    }
    index3.clear();

    b_start3++;
    beg3++;


}


    for(int l=0;l<11;l++){
    for(int p=0;p<11;p++){
        cout<<setw(5)<<p_arr3[l][p]<<setw(2);
    }
    cout<<endl;
    }
    ofstream outputFile("out_csv.txt");
        outputFile<<"___________________________________________________________________"<<endl<<endl;
    outputFile<<"    "<<"S1 plot table for people(column) and items(row)"<<endl;
    outputFile<<"___________________________________________________________________"<<endl<<endl;
    for(int b=0;b<11;b++){
        for(int y=0;y<11;y++){
            outputFile<<setw(5)<<p_arr[b][y]<<","<<setw(5);
        }
        outputFile<<"\n";
    }outputFile<<endl<<endl;
        outputFile<<"___________________________________________________________________"<<endl<<endl;
    outputFile<<"    "<<"S2 plot table for people(column) and items(row)"<<endl;
    outputFile<<"___________________________________________________________________"<<endl<<endl;
    for(int b=0;b<11;b++){
        for(int y=0;y<11;y++){
            outputFile<<setw(5)<<p_arr2[b][y]<<","<<setw(5);
        }
        outputFile<<"\n";
    }outputFile<<endl<<endl;
    outputFile<<"___________________________________________________________________"<<endl<<endl;
    outputFile<<"    "<<"S3 plot table for people(column) and items(row)"<<endl;
    outputFile<<"___________________________________________________________________"<<endl<<endl;
    for(int b=0;b<11;b++){
        for(int y=0;y<11;y++){
            outputFile<<setw(5)<<p_arr3[b][y]<<","<<setw(5);
        }
        outputFile<<"\n";
    }
    outputFile.close();
}
    /*
    for(int i=0;i<product_dis.size();i++){
        arr[(product_dis[i])-1]=1;

    }
    for(int x=0;x<10;x++){
        cout<<arr[x];
    }
    */




























