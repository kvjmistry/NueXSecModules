// A root script to take the varied cross section, recalculate and get an
// uncertainty

// Function to calculate the data cross section
double CalcDataXSec(double sel, double bkg , double flux,
                    double targets, double intime_cosmics_bkg, double intime_cosmic_scale_factor,
                    double dirt, double dirt_scale_factor, double mc_scale_factor, double efficiency ){

    bool DEBUG{true};

    if (DEBUG) std::cout << 
    "DEBUG:\n"<<
    "sel:\t" << sel << "\n" << 
    "bkg:\t" << bkg  << "\n" << 
    "flux:\t" << flux << "\n" << 
    "targets:\t" << targets << "\n" << 
    "intime_cosmics_bkg:\t" << intime_cosmics_bkg << "\n" << 
    "intime cosmic scale factor:\t" << intime_cosmic_scale_factor << "\n" << 
    "dirt:\t" << dirt << "\n" << 
    "dirt scale factor:\t" << dirt_scale_factor << "\n" << 
    "mc scale factor:\t" << mc_scale_factor << "\n" << 
    "efficiency:\t" << efficiency << std::endl;

    if (DEBUG) std::cout << "Total Scaled background:\t" <<  (intime_cosmics_bkg * intime_cosmic_scale_factor) - (dirt * dirt_scale_factor) - (bkg * mc_scale_factor) << std::endl;	

    return (sel - (intime_cosmics_bkg * intime_cosmic_scale_factor) - (dirt * dirt_scale_factor) - (bkg * mc_scale_factor)) / (efficiency * targets * flux); 
}
// ------------------------------------------------------------------------------------------------------------


void plot_var_bkg(){
    
    // A vector with the variations with no threshold
    std::vector<std::string> params = { 
        "BNBCV",
        "BNBwithDIC",
        "BNBdataSCE",
        "BNBdeadSaturatedChannels",
        "BNBLArG4BugFix",
        "BNBDLup",
        "BNBDLdown",
        "BNBDTup",
        "BNBDTdown",
        "BNBnoiseAmpUp",
        "BNBnoiseAmpDown",
        "BNBaltDeadChannels",
        "BNBstretchResp",
        "BNBsqueezeResp",
        "BNBupPEnoise",
        "BNBEnhancedTPCVis",
        "BNBBirksRecomb",
        "BNBdownPEnoise"};


    // Flux
    const double flux_mc{4.19844e+10};  // POT Scaled divide these to get scale factor
    const double flux_gsimple_data{5383349994.0}; //-- gsimple flux --
    // const double flux_gsimple_data{4.43336e+09}; //-- gsimple flux with threshold--
    const double POTScale_MC{1.82027e+21}; // MC POT Scale
    const double POTScale{2.334e+20};

    // Num Targets
    const double targets_mc{3.50191e+31};
    const double targets_data{3.4723e+31};

    // DATA
    const double intime_cosmics_bkg{81};                // Number of intime cosmics for background
    const double num_selected_data{214};                // The number of selected events in data
    const double intime_cosmic_scale_factor{1.0154};    // Scale factor to apply to the intime cosimic background
    const double mc_scale_factor{0.1301};               // Scale factor to apply to the mc background
    const double dirt_scale_factor = 0.16411;

    const double n_dirt{30};
    double n_bkg{1.04*356};

    const double efficiency{642.0/7103.0};

    

    // Make flux calculation -- choice of gsimple or dk2nu flux controlled by bool at top of code
    double Data_x_sec = CalcDataXSec(num_selected_data, n_bkg, flux_gsimple_data, targets_data, intime_cosmics_bkg, intime_cosmic_scale_factor, n_dirt, dirt_scale_factor, mc_scale_factor, efficiency );
    std::cout << "\033[1;33mNew DATA X-section [10^-39 cm^2]\t\t" << Data_x_sec/1.0e-39 << "\033[0m"<<std::endl;
       
    std::cout << "\033[1;33mUncertainty[10^-39 cm^2]\t\t" << 100* (4.76548 - (Data_x_sec/1.0e-39))/4.76548  << "\033[0m"<<std::endl;

    // gSystem->Exit(0);
} // END
// ------------------------------------------------------------------------------------------------------------