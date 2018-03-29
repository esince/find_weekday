/*Esin Ece Aydin 150160151 
*/

#include<stdio.h> //printf & scanf
#include<stdlib.h> // EXIT_SUCCESS

int main(){
    int year, month, day;
    int end_year;
    int first_two_digits = 0;
    int last_two_digits = 0;
    int weekday;
    int next_year;
    int count;
    int new_weekday = 0;
    int repeat_date = 0;
    
    
    printf("Enter date [year month day]: ");
    scanf("%d %d %d", &year, &month, &day);
    
    
    //to check input is valid or not, if input is not valid prompt failure message:
    switch(month){  
        case 1:
        case 3: 
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(day>31){
                printf("Invalid date.\n");
                return EXIT_FAILURE;
            }
             break;
        case 2:
            if(day>28){
                printf("Invalid date.\n");
                return EXIT_FAILURE;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day>30){
              printf("Invalid date.\n");
              return EXIT_FAILURE;
            }
             break;
            
    }

    if(month > 12){
	printf("Invalid date.\n");
        return EXIT_FAILURE;
    }

    printf("Enter end year: ");
    scanf("%d", &end_year);
    
    if(month <= 2){
        month += 12;
        year--;
    }
   
    //to calculate first_two_digits:
    first_two_digits = year / 100; 
    //to calculate last_two_digits and find new month and year value if month is january or february:
    last_two_digits  = year % 100;
    
    //to determine which weekday for given date corresponds to:
    weekday =  day + 13*(month + 1)/ 5  + last_two_digits + last_two_digits / 4 + first_two_digits / 4 + 5 * first_two_digits;
    weekday = weekday % 7;
    
    if(weekday == 0)
       printf("It's a Saturday.\n");
    else if(weekday == 1)
        printf("It's a Sunday.\n");
    else if(weekday == 2)
        printf("It's a Monday.\n");
    else if(weekday == 3)
        printf("It's a Tuesday.\n");
    else if(weekday == 4)
        printf("It's a Wednesday.\n");
    else if(weekday == 5)
        printf("It's a Thursday.\n");
    else if(weekday == 6)
        printf("It's a Friday.\n");
     
    
    next_year = year + 1;
    
    for(count = next_year; count <= end_year; count++){
		if (month <= 2){
			month += 12;
			count--;
		}

		//to calculate first_two_digits:
		first_two_digits = count / 100;
		//to calculate last_two_digits and find new month and year value if month is january or february:
		last_two_digits = count % 100;
        new_weekday = day + 13*(month + 1)/ 5  + last_two_digits + last_two_digits / 4 + first_two_digits / 4 + 5 * first_two_digits;
        new_weekday = new_weekday % 7;
        
        
        if(new_weekday == weekday)
            repeat_date++;
    }
    printf("Same day-and-month on same weekday between %d and %d: %d\n", next_year, end_year, repeat_date);
    
       
       
    return EXIT_SUCCESS;
}










