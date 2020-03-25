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
        "CV",
        "DIC",
        "SCE",
        "dead Sat. Chan.",
        "LArG4BugFix",
        "DL",
        "DT",
        "noiseAmp",
        "alt. Dead Chan.",
        "stretch Resp",
        "squeeze Resp",
        "PE Noise",
        "Enhanced TPC Vis.",
        "Birks Recomb."};

    std::vector<double> percentages= { 
        1.0,  // CV
        1.26, // DIC
        1.04, // SCE
        1.04, // DeadSatChan
        1.13, // LARG4BugFix 
        1.07, // DL
        1.02, // DT
        1.03, // noise Amp
        1.01, // alt dead channels
        1.06,  // stretch resp
        1.08, // squeeze resp
        1.04, // pe noise
        1.02, // tpc vis
        1.03}; // Birks


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

    const double efficiency{642.0/7103.0};

    TH1D *hist = new TH1D("hist","", params.size()+2, 0, params.size()+2);

   double Quad{0};

    
    for (unsigned int i =0; i < percentages.size(); i++){
        double n_bkg = percentages.at(i)*356;
        std::cout << params.at(i) << "\n"<<std::endl;

        // Make flux calculation -- choice of gsimple or dk2nu flux controlled by bool at top of code
        double Data_x_sec = CalcDataXSec(num_selected_data, n_bkg, flux_gsimple_data, targets_data, intime_cosmics_bkg, intime_cosmic_scale_factor, n_dirt, dirt_scale_factor, mc_scale_factor, efficiency );
        std::cout << "\033[1;33mNew DATA X-section [10^-39 cm^2]\t\t" << Data_x_sec/1.0e-39 << "\033[0m"<<std::endl;
        
        std::cout << "\033[1;33mUncertainty[10^-39 cm^2]\t\t" << 100* (4.76548 - (Data_x_sec/1.0e-39))/4.76548  << "\033[0m"<<std::endl;

        double uncertainty = 100* (4.76548 - (Data_x_sec/1.0e-39))/4.76548;

        if (i !=0) hist->Fill( params.at(i).c_str(), 100* (4.76548 - (Data_x_sec/1.0e-39))/4.76548 );

        Quad+=  uncertainty * uncertainty;
    }

    Quad = std::sqrt(Quad);

    hist->Fill( "  ", 0 );
    hist->Fill( "Quadrature Sum", Quad );
    hist->Fill( "  ", 0 );
    
   
    gStyle->SetPaintTextFormat("4.2f");
    gStyle->SetOptStat(0); // say no to stats box
    
    TCanvas* c = new TCanvas();
    hist->SetLineColor(kViolet-6);
    hist->SetLineWidth(3);
    hist->GetYaxis()->SetTitle("Percentage Uncertainty %");
    hist->LabelsOption("v");
    gPad->SetBottomMargin(0.29);

    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);
    hist->SetMarkerSize(1.8);
    gPad->SetLeftMargin(0.15);

    hist->GetYaxis()->SetRangeUser(0,20);

    hist->Draw("hist, text00");

    std::cout << "Quadrature Sum: " << Quad << std::endl; 

    c->Print("plots/Detector_Uncertainties.pdf");

    



    // gSystem->Exit(0);
} // END
// ------------------------------------------------------------------------------------------------------------