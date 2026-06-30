#include <bits/stdc++.h>
// #include <math.h>
// #include <string>

using namespace std;

void pattern1(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern3(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout << j+1;
        }
        cout << endl;
    }
}
void pattern4(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout << i+1;
        }
        cout << endl;
    }
}
void pattern5(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern6(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            cout << j+1;
        }
        cout << endl;
    }
}
void pattern7(int n) {
    for(int i=0;i<n;i++) {

        //space
        for(int k=0;k<n-i-1;k++) {
            cout << " ";
        }
        
        //stars
        for(int j=0;j<2*i+1;j++) {
            cout << "*";
        }

        // //space again
        // for(int k=0;k<n-i-1;k++) {
        //     cout << " ";
        // }
        cout << endl;
    }
}
void pattern8(int n) {
    for(int i=n;i>0;i--) {

        //space
        for(int k=0;k<n-i;k++) {
            cout << " ";
        }
        
        //stars
        for(int j=0;j<2*i-1;j++) {
            cout << "*";
        }

        //sapace again
        // for(int k=0;k<n-i-1;k++) {
        //     cout << " ";
        // }
        cout << endl;
    }
}
void pattern9(int n) {
    for(int i=1;i<=2*n-1;i++) {
        int stars=i;
        if(i>n) stars = 2*n-i;
        for(int j=1;j<=stars;j++) {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern10(int n) {
    for(int i=0;i<n;i++) {
        int start=1;
        if(i%2==0) start=1;
        else start=0;
        for(int j=0;j<=i;j++) {
            cout << start;
            start = 1-start;
        }
        cout << endl;
    }
}
void pattern11(int n) {
    // int space = 2*(n-1);
    for(int i=0;i<n;i++) {
        //numbers
        for(int j=0;j<=i;j++) {
                cout << j+1;
        }

        //spaces
        for(int j=0;j<2*(n-i)-2;j++) {       // j<space
            cout << " ";
        }

        //numbers
        for(int j=i;j>=0;j--) {
                cout << j+1;
        }
        cout << endl;
        // space -= 2;
    }
}
void pattern12(int n) {
    int num=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}
void pattern13(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout << char(65+j) << " ";
        }
        cout << endl;

        // for(char ch = 'A';ch <= 'A'+i;ch++) {
        //     cout << ch << " ";
        // }
        // cout << endl;
    }
}
void pattern14(int n) {
    for(int i=n;i>=0;i--) {
        for(int j=0;j<=i;j++) {
            cout << char(65+j) << " ";
        }
        cout << endl;
    }
}
void pattern15(int n) {
    int ch=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout << char(65+ch) << " ";
        }
        ch++;
        cout << endl;
    }
}
void pattern16(int n) {
    for(int i=0;i<n;i++) {

        //space
        for(int k=0;k<n-i-1;k++) {
            cout << " ";
        }

        //characters
        char ch='A';
        int breakpoint = (2*i+1)/2;
        for(int j=0;j<2*i+1;j++) {
            cout << ch;
            if(j>=breakpoint) ch--;
            else ch++;
        }

        // // space again
        // for(int k=0;k<n-i-1;k++) {
        //     cout << " ";
        // }
        cout << endl;
    }
}
void pattern17(int n) {
    // Upper half
    for (int i = n; i >= 1; i--) {

        for (int j = 1; j <= i; j++)
            printf("*");

        for (int j = 1; j <= 2 * (n - i); j++)
            printf(" ");

        for (int j = 1; j <= i; j++)
            printf("*");

        printf("\n");
    }

    // Lower half
    for (int i = 2; i <= n; i++) {

        for (int j = 1; j <= i; j++)
            printf("*");

        for (int j = 1; j <= 2 * (n - i); j++)
            printf(" ");

        for (int j = 1; j <= i; j++)
            printf("*");

        printf("\n");
    }
}
void pattern18(int n) {
    //Method 1
    // int spaces=2*n-2;
    
    // //upper half
    // for(int i=0;i<n;i++) {
    //     //stars
    //     for(int j=0;j<=i;j++) cout << "*";

    //     //spaces
    //     for(int j=0;j<spaces;j++) cout << " ";

    //     //stars
    //     for(int j=0;j<=i;j++) cout << "*";
    // spaces-=2;
    // cout << endl;
    // }

    // //lower half
    // spaces=2;
    // for(int i=1;i<n;i++) {
    //     //stars
    //     for(int j=0;j<n-i;j++) cout << "*";

    //     //spaces
    //     for(int j=0;j<spaces;j++) cout << " ";

    //     //stars
    //     for(int j=0;j<n-i;j++) cout << "*";
    // spaces+=2;
    // cout << endl;
    // }

    //Method 2
    for(int i = 1; i <= 2 * n - 1; i++) {

        int stars;

        if(i <= n)
            stars = i;
        else
            stars = 2 * n - i;

        // Stars
        for(int j = 1; j <= stars; j++)
            cout << "*";

        // Spaces
        for(int j = 1; j <= 2 * (n - stars); j++)
            cout << " ";

        // Stars
        for(int j = 1; j <= stars; j++)
            cout << "*";

        cout << endl;
    }

}


int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        pattern18(n);
        cout << endl;
    }
}


