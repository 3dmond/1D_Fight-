

#include <iostream>
#include <random>
#include <ctime>

int main()
{
    int humans, skeletons;
    std::cout<<"Input the number of fighters below:\n";
    std::cout<<"Humans: ";std::cin>>humans;std::cout<<"\n";
    std::cout<<"Skeletons: ";std::cin>>skeletons;std::cout<<"\n";
    std::default_random_engine randomGenerator (time(0));
    std::uniform_int_distribution atackHit (1, 100);
    int humanHealth, skeletonHealth;
    humanHealth = 100 * humans;
    skeletonHealth = 100 * skeletons;
    atackHit(randomGenerator);
    int humanAtack, skeletonAtack;
    while (humanHealth > 0 && skeletonHealth > 0)
    {
        humanAtack = atackHit(randomGenerator);
        skeletonAtack = atackHit(randomGenerator);
        if (humanAtack < 30)
            {
                skeletonHealth -= humanAtack;
            }
        if (skeletonAtack < 30)
            {
                humanHealth -= skeletonAtack;
            }
    }
    int survivors;
    std::string survivorType;
    if (humanHealth > 0)
    {
        survivorType = "Humans";
        int a = humanHealth % 100;
        int b = humanHealth / 100;
        if (a > 0){
            survivors = b+1;
        }
        else{
            survivors = b;
        }
    std::cout<<"There were "<<skeletons<<" skeleton deaths and "<<humans - survivors<<" human deaths. The victory was for the "<<survivorType<<" with "<<survivors<<" of them surviving."<<std::endl;
    }else if (skeletonHealth > 0)
    {
        survivorType = "Skeletons";
        int a = skeletonHealth % 100;
        int b = skeletonHealth / 100;
        if (a > 0){
            survivors = b+1;
        }
        else{
            survivors = b;
        }
    std::cout<<"There were "<<humans<<" human deaths and "<<skeletons - survivors<<" skeleton deaths. The victory was for the "<<survivorType<<" with "<<survivors<<" of them surviving."<<std::endl;
    }
    else {
        std::cout<<"The war had no survivors. All humans and skeletons were casualties of the war. Say no to war!!!"<<std::endl;
    }

    return 0;
}
