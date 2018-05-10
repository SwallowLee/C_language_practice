#include <vector>
#include<math.h>

namespace quiz1{

	template<class T>
        T EuclideanDistance(const std::vector<T>& Pa,
                            const std::vector<T>& Pb){

                if( Pa.size() != Pb.size() )
                        throw ":(";

                T Distance = 0;

                int it;
                for(it=0;it<3;it++)
                {
                        if(Pa[it]*Pa[it]-Pa[it]*Pb[it]>=0)
                                Distance=Pa[it]*Pa[it]-Pb[it]*Pb[it];
                        else
                                Distance=Pb[it]*Pb[it]-Pa[it]*Pa[it];
                }
                //std::cout<<Distance<<std::endl;
                Distance=sqrt(Distance);
                return Distance;

                }

        }
