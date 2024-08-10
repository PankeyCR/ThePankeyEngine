
#ifndef higgs_config_hpp
    #define higgs_config_hpp

    #ifndef higgs_config_method
        void higgs_config_method_(){}

        #define higgs_config_method higgs_config_method_
    #endif

    namespace higgs{

        void higgsConfig(){
            higgs_config_method();
        }

    }

//////////////////////////////////////////////////////////////

#endif