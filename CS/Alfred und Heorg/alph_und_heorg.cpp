#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
	ifstream fin;
	ofstream fout;

    int n;
    int m;
    int k;

    int x;
    int y;
	fin.open("input.txt");
	fout.open("output.txt");
    fin>>n;
    fin>>m;
    fin>>k;
    bool** list = new bool*[n];

    for (int i = 0; i < n; i++) {
        list[i]= new bool[m];
    }
	//reading a file if black then true element of matrix, else if white then false
    for(int i=0;i<k;++i){
        fin>>x;
        fin>>y;
        list[x][m-1-y]=true;
    }
	//inserting false in matrix where element is not true
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(list[i][j]!=true){
                list[i][j]=false;
            }
        }
    }
	//printing an array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<list[j][i]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    int count=0;
	bool help=false;
	bool exit=false;
	int saved_k=0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

			if(list[j][i]==true){
				for (int k = i; k < m; k++) {

					cout<<"--"<<saved_k<<endl;
					help=false;
                    if(k==i){

                        for (int l = j; l < n; l++) {
							saved_k=j;
                            list[l][k]=!(list[l][k]);

                        }
                    }
                    else{
                        for (int l = 0; l < n; l++) {
							if (list[l][k]==true){
								if(l<=saved_k){
									saved_k=l;
								}

								cout<<"+-+-"<<saved_k<<"="<<l<<"="<<k<<"=" <<endl;
								help=true;
							}
							if ((help==true)||(l>=saved_k)){
								list[l][k]=!(list[l][k]);

							}

                        }
                    }
					for (int z = 0; z < m; z++) {
						for (int zz = 0; zz < n; zz++) {
							cout<<list[zz][z]<<"\t";
						}
						cout<<endl;
					}
					cout<<endl;
                    cout<<endl;

                }
                cout<<endl;
                count++;

            }
        }
		if (exit==true){
			break;
		}
    }
    cout<<count;
	fin.close();
	fout.close();

    return 0;
}
