#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Records{
    	string product;
	double cost;
	int in_stock;
	int on_order;
	};
	
// Write your functions here
void printData(Records *funArr, int count2){
	int num = 1;
	for(int i=0; i<count2; i++){
	cout << "Record #" << num << ": "<< funArr[i].product <<" "<< funArr[i].cost <<" "<< funArr[i].in_stock <<" "<< funArr[i].on_order << endl;
	num++;
	}
}

int loadData(Records *funArr, string filename){
	int count=0;
	ifstream readF;
   	readF.open(filename.c_str());

	while(!readF.eof()){
		readF >> funArr[count].product;
		readF >> funArr[count].cost;
		readF >> funArr[count].in_stock;
		readF >> funArr[count].on_order;
	    count++;
	}
	readF.close();
	return count;
}

void saveData(Records *funArr, int count3, string filename1){
	cout << "Saving data to file" << endl;
	ofstream writeF;
	writeF.open(filename1.c_str());
	
	for(int i=0; i<count3; i++){
		writeF << funArr[i].product << " ";
		writeF << funArr[i].cost << " ";
		writeF << funArr[i].in_stock << " ";
		writeF << funArr[i].on_order;
		writeF << endl;
	}
	writeF.close();
}

int main()
{
    // Write the code of the main function here	
	int count1;
    string filename1 = "data_in.txt";
    string filename0 = "data_out.txt";
    
    Records *recArr = new Records[10];
    
    count1 = loadData(recArr, filename1);
    
    int x=0;
    int userVal, cngVal;
    while(x==0){
    	int newVal = 1;
    	cout << "Pick an option from the following: " << endl;
		cout << "1 - Display current records" << endl;
		cout << "2 - Modify a specific record" << endl;
		cout << "3 - Save your work to file" << endl;
		cout << "4 - End program" << endl;
		cout << "Enter number of choice: ";
		cin >> userVal;
    	if(userVal==1){
    		printData(recArr, count1);
		}
		else if(userVal==2){
			printData(recArr, count1);
			cout << "Enter record number to modify: ";
			cin >> cngVal;
			if(cngVal>count1){
				cout << "Value greater than size of array, please try again." << endl;
				continue;
			}
			if(cngVal<=0){
				cout << "Value zero or negative, please try again." << endl;
				continue;
			}
			cout << "Current values: ";
			cout << recArr[cngVal-1].product <<" "<< recArr[cngVal-1].cost <<" "<< recArr[cngVal-1].in_stock <<" "<< recArr[cngVal-1].on_order << endl;
			cout << "Enter new value for Product Type: ";
			cin >> recArr[cngVal-1].product;
			cout << "Enter new value for Product Cost: ";
			cin >> recArr[cngVal-1].cost;
			cout << "Enter new value for Product Stock: ";
			cin >> recArr[cngVal-1].in_stock;
			cout << "Enter new value for Product On Order: ";
			cin >> recArr[cngVal-1].on_order;
			cout << endl;
			cout << "New values are: " << recArr[cngVal-1].product <<" "<< recArr[cngVal-1].cost <<" "<< recArr[cngVal-1].in_stock <<" "<< recArr[cngVal-1].on_order << endl;
			cout << "Are you done modifying this record?" << endl << "1 - Yes" << endl << "2 - No" << endl;
			cout << "Enter response: ";
			cin >> newVal;	
		}
		else if(userVal==3){
			saveData(recArr, count1, filename0);
		}
		else if(userVal==4){
			cout << "Task complete, closing program";
			x=1;
		}
		cout << endl;
	}
}
