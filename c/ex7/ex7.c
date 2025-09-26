#include<stdio.h>
int main(){
    int bugs=100;
    double bug_rate=1.3;
    printf("You have %d bugs at the imaginary rate of %f.\n",
        bugs,bug_rate);
    unsigned long universe_of_defects=922337203685477580;
    printf("The entire universe has %ld bugs.\n",
        universe_of_defects);
    double expected_bugs=bugs*bug_rate;
    printf("You are expected to have %f bugs.\n",
        expected_bugs);
    double part_of_universe = expected_bugs / universe_of_defects;
    printf("That is only a %e portion of the universe.\n",
            part_of_universe);
    char nul_byte = '2';
    int care_percentage = bugs * nul_byte;//int會與字符的ascii碼相稱
    printf("Which means you should care %d%%.\n",
            care_percentage);

    return 0;
}
