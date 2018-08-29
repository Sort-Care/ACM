/*
 *  Uva10114 Loansome Car Buyer
 */
#include <stdio.h>

int MONTHSIZE = 110;


int main(){
    int TM, rc;//total months, record count
    double dp, loan;//down payment, loan amount
    double records[MONTHSIZE];
    double depr_value[MONTHSIZE];
    double owed_value;
    double total_value;
    double monthly;
    

    int fast, slow;
    while (scanf("%d %lf %lf %d", &TM, &dp, &loan, &rc), (TM>0)){
//        printf("first loop\n");
        
        total_value = dp + loan;
        owed_value = loan;
        monthly = loan / TM;
        
        
            //read in the depreciate records
        fast = 0;
        slow = 0;
        double depv; //depreciate value
        
        while (rc -- ){
            scanf("%d %lf", &fast, &depv);
//            printf("fast at : %d\n", fast);
            
            while(slow < fast){
//                printf("assign %d to %d\n", slow+1, slow);
                records[slow+1] = records[slow];
                slow ++;
                
            }
            records[fast] = depv;
        }
        fast ++;
        while (fast <= TM){
            records[fast] = records[fast -1];
            fast ++;
        }

            //for (int j = 0; j <= TM ; j++) printf("%lf\n", records[j]);
        
        
        
        int i = 0;
        depr_value[i] = total_value * (1 - records[i]);
            //printf("depr value 0: %lf\n", depr_value[i]);
        
        while (depr_value[i] <= owed_value){
            i++;
            depr_value[i] = depr_value[i-1] * (1 - records[i]);
                //printf("depr value %d: %lf\n", i, depr_value[i]);
            
            owed_value -= monthly;
                //printf("owed_value : %lf\n", owed_value);
        }
        
        char str[2][8] = {"month", "months"};
        int index = 1;
        
        if (i == 1) index = 0;
        
        printf("%d %s\n", i, str[index]);
    }
    
    
    return 0;
    
}


/*
 * Input : information for several loans
 * Each Loan: 
 * One line containing 
 *      the duration in months
 *      the down payment
 *      the amount of the loan
 *      the number of depreciation records that follow
 * Each depreciation record:
 * one line with a month number and depreciation precentage
 * If a month is not listed, then the previous depreciation precentage applies.
 * The end of the input is signalled by a negative loan duration
 * 0% interest loan: car's initial value = Loan Amount + Down payment.
 * Do not round values to a whole number of cents.
 */
