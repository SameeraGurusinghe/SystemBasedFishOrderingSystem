	#include<stdio.h>
	#include<string.h>
	#include<time.h>
	#include<stdlib.h> /*abort() — Stop a program*/

	int main(){
		float bill;
	    double rate[7];
	    int iqty,bid,n;
	    char date[15],*item[7],cname[20],addr[80],phone[11];
	    item[0]="1. Madu Fish";
	    item[1]="2. Moora Fish";
	    item[2]="3. Alaguduwa";
	    item[3]="4. Thalapath";
	    item[4]="5. Salayo Fish";
	    item[5]="6. Balaya Fish";
	    item[6]="7. Dallo Fish";
	    rate[0]=1000;
	    rate[1]=800;
	    rate[2]=650;
	    rate[3]=900;
	    rate[4]=250;
	    rate[5]=750;
	    rate[6]=1800;

		double rate2[7];
	    int siqty,sbid,sn;
	    char sdate[15],sname[20],sid[80];
	    rate2[0]=870;
	    rate2[1]=730;
	    rate2[2]=600;
	    rate2[3]=850;
	    rate2[4]=220;
	    rate2[5]=700;
	    rate2[6]=1700;

		/*******Display Time**********/
		char cur_time[128];
		time_t t;
		struct tm* ptm;

		t = time(NULL);
		ptm = localtime(&t);

		strftime(cur_time, 128, "%d-%b-%Y %H:%M:%S",ptm);

	    /*******System start*******/
	    printf("\n****************************************Lanka Digital Fish Shop****************************************\n");
		printf("\n\nLanka Digital Fish Shop is a online Platform for both of customers and sellers to buy and sell Fish/ Fishes. We will give a best support service to all our customers and Suppliers.\n");
		char who;
		
		/*******Identify whether user is customer or fish supplier*******/
		printf("We need to identify you are customer or fish supplier.\n");
		printf("\nC = Customer\n");
		printf("S = Fish Supplier\n");

		printf("\nKindly select your identity (C or S). : ");
		scanf("%s",&who);
		if(who=='C'||who=='c'){
		
		
	    printf("\n\nDear Customers,\nWe are happy to give you best services. Always we are delivery your item/s without any delivery costs.\n\n");

        /*******Customer input for get Name & Address*******/
	    printf("Enter your name :");
	    scanf("%s",cname);     
	    printf("\nEnter your home address :");
	    scanf("%s",addr);

	    
	    printf("\n*****************Welcome to Lanka Digital Fish Shop*****************\n\nHello %s,",cname);
        
        /*******Display current fishes price chart for selling*******/
	    printf("\n\nFishes price chart (All prices are equal to 1 KG)\n");
	    for(int i = 0; i < 7; i++)
	    {
		printf("%s :",item[i]);
		printf(" %.2f\n",rate[i]); 
	    }
	    
        /*******Customer input for identify fish types*******/
	    printf("\nHow many fish types you need to buy : ");
	    scanf("%d",&iqty);
	    int type[iqty];
	    float qty[iqty];
	    
	    /*******Customer input for fish types and Quantities*******/
	    printf("\nTo buy fish/ fishes select a number/s according to the above list.\n");
	    for(int i = 0; i < iqty; i++)
	    {
		printf("\nFish type : ");
		scanf("%d",&type[i]);
		printf("Input the Quantity (KG) : ");
		scanf("%f",&qty[i]);
	    }


	    /*******Display Customer selected fishes*******/
	    printf("\nYou have selected ");
	    for(int i=0; i < iqty; i++)
	    {
		printf("%d, ",type[i]);
	    }
	    
	    printf("types of fish/ fishes.");
	    printf("\nQuantities are ");
	    
	    for(int i=0; i < iqty; i++)
	    {
		printf("%.2f, ",qty[i]);
	    }
        
        
        /*******file handling*******/
		FILE *fileText=fopen("D:\\Customer Bill.txt","w");
		fprintf(fileText, "\n\n\t\t\tLANKA DIGITAL FISH SHOP - CUSTOMER INVOICE");
		fprintf(fileText, "\n\n*********************************************Invoice*********************************************\n\n");
	    fprintf(fileText, "Fish type/s\t\t\t Quantity(KGs)\t\t\t Total\t\t\n");


        /*******Customer Invoice print in command prompt*******/
	    printf("\n\n\n\n\n****************************************Invoice****************************************\n");
	    printf("\nFish type/s\t\t\tQuantity (KGs)\t\t\tTotal\n");
	    double tot=0;
	    for(int i = 0; i < iqty; i++)
	    {
		printf("%s \t\t\t",item[type[i]-1]);
		fprintf(fileText, "%s \t\t\t",item[type[i]-1]);
		printf("%.2f\t\t\t",qty[i]);
		fprintf(fileText, "%.2f \t\t\t", qty[i]);
		double subtot=(qty[i])*(rate[type[i]-1]);
		printf("%.2f\n",subtot);
		fprintf(fileText, "%.2f \n", subtot);
		tot=tot+subtot;
	    }

        /*******Payment method selection*******/
	    char paym;
	    printf("\nSub Total is %.2f LKR.\n",tot);
	    printf("\nSelect your payment method.(M or C)\nM = money payment\nC = credit card payment\nDiscount for credit card payment is 5\nMy payment mathod is : ");
	    scanf("%s",&paym);
	    double dis=0;
	    if(paym=='C'||paym=='c'){
		dis=(tot*5)/100;
	    }

    
	    else if (paym=='M'||paym=='m'){
	    }
	    
	    else{
	        printf("\nError : Invalid Input.! System");
	        abort();
	    }
	    
	    /*******Discount and SubTotal calculation part*******/
	    printf("\nYour discount is : %.2f LKR.\n",dis);
		fprintf(fileText, "\nYour discount is : %.2f LKR.\n",dis);
	    printf("%s You need to pay : %.2f LKR.",cname,(tot-dis));
		fprintf(fileText, "%s, You need to pay : %.2f LKR.\n",cname,(tot-dis));

	    printf("\nWe will delivery your purchases to '%s' address withing 3 hours.\n\n",addr);
		fprintf(fileText, "\nWe will delivery your purchases to '%s' address withing 3 hours.\n\n",addr);

	    printf("If you need any assistance, do not hesitate to contact Lanka Digital Fish Shop on 0915 71 44 44\n");
		printf("\n\t\t\t\tTime : %s\n",cur_time);

	    printf("\n\n*************************************Thank you**************************************\n");

		fprintf(fileText, "\nIf you need any assistance, do not hesitate to contact Lanka Digital Fish Shop on 0915 71 44 44\n\n");
		
		fprintf(fileText, "\n\t\t\t\tTime : %s\n",cur_time);
	    fprintf(fileText, "\n\n********************************************Thank you********************************************\n");
	   }
	   
	    /*******If user will Fish supplier*******/
	    else if(who=='S'||who=='s'){

		printf("\n\nDear Fish Supplier,\nWe are happy to business with you. It is a great opportunity to us.\n\n");

        /*******Supplier input for get Supplier ID & Name*******/
	    printf("Enter supplier no :");
	    scanf("%s",sid);     
	    printf("\nEnter your name :");
	    scanf("%s",sname);

	    
	    printf("\n*****************Welcome to Lanka Digital Fish Shop*****************\n\nHello Fish Supplier %s,",sname);

        /*******Display current fishes price chart for buying*******/
	    printf("\n\nThis is the our buyig price chart according to the Agreement N0 : 03A7 (All prices are equal to 1 KG)\n");
	    for(int i = 0; i < 7; i++)
	    {
		printf("%s :",item[i]);
		printf(" %.2f\n",rate2[i]); 
	    }

        /*******Supplier input for identify fish types*******/
		printf("\nHow many fish types You can sell us ? : ");
	    scanf("%d",&siqty);
	    int stype[siqty];
	    float sqty[siqty];
	    
	    /*******Supplier input for fish types and Quantities*******/
	    printf("\nTo sell fish/ fishes select a number/s according to the above list.\n");
	    for(int i = 0; i < siqty; i++)
	    {
		printf("\nFish type : ");
		scanf("%d",&stype[i]);
		printf("Input a supply Quantity (KG) : ");
		scanf("%f",&sqty[i]);
	    }

        /*******Display Supplier selected fishes*******/
	    printf("\nYou have selected, \n");
	    for(int i=0; i < siqty; i++)
	    {
		printf("%s - %.2f KGs ",item[stype[i]-1], sqty[i]);
		printf("\n");
	    }

        /*******File handling*******/
		FILE *fileText=fopen("D:\\Supplier Bill.txt","w");
		fprintf(fileText, "\n\n\t\t\tLANKA DIGITAL FISH SHOP - SUPPLIER INVOICE");
		fprintf(fileText, "\n\n*********************************************Invoice*********************************************\n\n");
	    fprintf(fileText, "Fish type/s\t\t\t Quantity(KGs)\t\t\t Total\t\t\n");


        /*******Supplier Invoice print in command prompt*******/
	    printf("\n\n\n\n\n****************************************Invoice****************************************\n");
	    printf("\nFish type/s\t\tQty\t\tTotal\t\t\n");
	    double tot2=0;
	    for(int i = 0; i < siqty; i++)
	    {
		printf("%s\t\t\t",item[stype[i]-1]);
		fprintf(fileText, "%s\t\t\t",item[stype[i]-1]);
		printf("%.2f\t\t\t",sqty[i]);
		fprintf(fileText, "%.2f\t\t\t",sqty[i]);
		double subtot2=(sqty[i])*(rate2[stype[i]-1]);
		printf("%.2f\n",subtot2);
		fprintf(fileText, "%.2f\n",subtot2);
		tot2=tot2+subtot2;
	    }

        /*******Payment calculation part*******/
	    printf("\n\n%s we will pay you to : %.2f LKR.",sname,tot2);
		fprintf(fileText, "\n\n%s, we will pay you to : %.2f LKR.\n",sname,tot2);

		
	    fprintf(fileText, "\nPayment Details");
		fprintf(fileText, "\nName : %s",sname);
		fprintf(fileText, "\nSupplier No : %s\n",sid);

	    printf("\n\nIf you need any assistance, do not hesitate to contact Lanka Digital Fish Shop on 0915 71 44 44\n");
		printf("\n\t\t\t\tTime : %s\n",cur_time);

	    printf("\n\n********************************************Thank you********************************************\n");

		fprintf(fileText, "\nIf you need any assistance, do not hesitate to contact Lanka Digital Fish Shop on 0915 71 44 44\n\n");
		fprintf(fileText, "\n\t\t\t\tTime : %s\n",cur_time);
		
		
	    fprintf(fileText, "\n\n********************************************Thank you********************************************\n");

	}
	
    else{
        printf("\nError : Invalid Input.!");
    }

	 return 0;  
	}

