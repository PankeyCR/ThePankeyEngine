
#ifndef pankey_config_hpp
    #define pankey_config_hpp

    #ifndef pankey_config_method
        void pankey_config_method_(){}

        #define pankey_config_method pankey_config_method_
    #endif

    namespace pankey{

        void pankeyConfig(){
            pankey_config_method();
        }

    }

//////////////////////////////////////////////////////////////

#endif