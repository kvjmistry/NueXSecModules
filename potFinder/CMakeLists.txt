#include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
#include_directories( $ENV{PANDORA_INC} )
#include_directories( $ENV{LARPANDORACONTENT_INC} )

# define ROOTLIB
#set( ROOTLIB -L$ENV{ROOTSYS}/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl)

#link_libraries( ${LIB_NAME} -L$ENV{BOOST_LIB} -lboost_system ${ROOTLIB} )

art_make(
          MODULE_LIBRARIES
                   larsim_MCCheater_BackTracker_service
		   larpandora_LArPandoraInterface
                   #larpandora_LArPandoraContent

		   uboonecode_uboone_BasicTool_GeoAlgo
		   #uboonecode_uboone_SelectionTool_OpT0FinderBase
		   #uboonecode_uboone_SelectionTool_OpT0FinderAlgorithms
                   #uboone_UBFlashFinder

                   uboone_RawData
                   SignalShapingServiceMicroBooNE_service
                   larevt_CalibrationDBI_IOVData
                   larevt_CalibrationDBI_Providers
	  	   larcore_Geometry
		   larcore_Geometry_Geometry_service
		   lardataobj_RecoBase
                   lardataobj_AnalysisBase
                   lardata_Utilities
                   larsim_Simulation lardataobj_Simulation
                   nusimdata_SimulationBase
		   ${UBOONECODE_LIB}
		   ${LARDATA_LIB}
		   ${ART_FRAMEWORK_CORE}
		   ${ART_FRAMEWORK_PRINCIPAL}
                   ${ART_FRAMEWORK_BASIC}
		   ${ART_FRAMEWORK_SERVICES_REGISTRY}
                   ${ART_FRAMEWORK_SERVICES_OPTIONAL}
                   ${ART_FRAMEWORK_SERVICES_OPTIONAL_TFILESERVICE_SERVICE}
            	   ${ART_PERSISTENCY_COMMON}
            	   ${ART_PERSISTENCY_PROVENANCE}
            	   ${ART_UTILITIES}
            	   ${MF_MESSAGELOGGER}
            	   ${MF_UTILITIES}
            	   ${FHICLCPP}
            	   ${CETLIB}
            	   ${ROOT_GEOM}
            	   ${ROOT_XMLIO}
            	   ${ROOT_GDML}
            	   ${ROOT_BASIC_LIB_LIST}
		)

install_headers()
install_fhicl()
install_source()
