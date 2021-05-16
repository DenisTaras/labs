#include "Polinomial.hpp"
#include "Lineform.hpp"
#include "Sequence.hpp"
#include <iostream>
#include <complex>
#define CIN_FLUSH if (std::cin.peek()) std::cin.ignore()
const std::string MSG[] = {"1.EXIT  \n", "2. SumP  \n", "3. CompositionP  \n" , "4. ScalarP  \n" , "5. ValueP  \n","6. SumL  \n", "7. ScalarL  \n", "8. ValueP  \n" };
const int SMSG = 8;
int getmenu() {
    std::string error = "\n";
    int ch = 0;
    do {
        std::cout << error;
        error = "You're wrong. Try again!\n";
        for (int i = 0; i < SMSG; i++) {
        std::cout <<MSG[i];
        }
        puts("Make your choice: \n");
        ch = getchar() - '0';
        while (getchar() != '\n') {}    
    } while(ch < 1 || ch > SMSG);
    
    return ch;
}
int main(){
    int turn = 1;
    int res = 0;
     while(turn) {
        res = getmenu();
        switch(res) {
            case 1:{
                std::cout << "Goodbye";
                turn  = 0;
                CIN_FLUSH;
                break;
            }
            case 2:{
                std::cout <<"Choose type:\n 1.Integer\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch(choose){
                    case 1:{
                        int n;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P2(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<double> P3 = P1 + P2;
                        std::cout << "Result: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;
                        }
                    case 2:{
                        int n;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P2(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<std::complex<double>> P3 = P1 + P2;
                        std::cout << "Result: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;}
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                }
                break;   
            }
            case 3:{
                std::cout <<"Choose type:\n 1.Integer\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P2(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<double> P3 = P1 * P2;
                        std::cout << "Result: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P2(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<std::complex<double>> P3 = P1 * P2;
                        std::cout << "Result: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;}
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;} 
                }
                break;
            }
            case 4:{
                std::cout <<"Choose type:\n 1.Integer\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n;
                        double a;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        P1 *= a;
                        std::cout << "Result: " << P1 <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::complex<double> a;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        P1 *= a;
                        std::cout << "Result: " << P1 <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}    
                    }
                    break;    
                }
            case 5:{
                std::cout <<"Choose type:\n 1.Integer\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n;
                        double a,b;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        b = P1.gorner(a);
                        std::cout << "Result: " << b <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::complex<double> a,b;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        b = P1.gorner(a);
                        std::cout << "Result: " << b <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                    }
                break;    
                }
            case 6:{
                std::cout <<"Choose type:\n 1.Integer\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch(choose){
                    case 1:{
                        int n;
                        std::cout<< "Enter dimen\n";
                        std:: cin >> n;
                        Lineform<double> P1(n);
                        std::cout<< "Entter Linefom\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Lineform<double> P2(n);
                        std::cout<< "Entter Linefom\n";
                        std::cin >> P2;
                        Lineform<double> P3 = P1 + P2;
                        std::cout << "Result: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;
                        }
                    case 2:{
                        int n;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Lineform<std::complex<double>> P1(n);
                        std::cout<< "Entter Linefom\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Lineform<std::complex<double>> P2(n);
                        std::cout<< "Entter Linefom\n";
                        std::cin >> P2;
                        Lineform<std::complex<double>> P3 = P1 + P2;
                        std::cout << "Result: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;}
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                }
                break;   
            }
            case 7:{
                 std::cout <<"Choose type:\n 1.Integer\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n;
                        double a;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<double> P1(n);
                        std::cout<< "Entter Lineform\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        P1 *= a;
                        std::cout << "Result: " << P1 <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::complex<double> a;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<std::complex<double>> P1(n);
                        std::cout<< "Entter Lineform\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        P1 *= a;
                        std::cout << "Result: " << P1 <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}    
                    }
                    break;    
            }
            case 8:{
                 std::cout <<"Choose type:\n 1.Integer\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n;
                        double a,b;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<double> P1(n);
                        std::cout<< "Entter Lineform\n";
                        std::cin >> P1;
                        std::cout<< "Enter vector\n";
                        Lineform<double> P2(n);
                        std:: cin >> P2;
                        b = P1.value(P2);
                        std::cout << "Result: " << b <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::complex<double> a,b;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<std::complex<double>> P1(n);
                        std::cout<< "Entter Lineform\n";
                        std::cin >> P1;
                        std::cout<< "Enter vector\n";
                        Lineform<std::complex<double>> P2(n);
                        std:: cin >> P2;
                        b = P1.value(P2);
                        std::cout << "Result: " << b <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                    }
                break;    
            }
        }
    }
    return 0;
}