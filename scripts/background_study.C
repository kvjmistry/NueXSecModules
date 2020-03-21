// Root script for quickly reweighting selected background events to avoid having to run the selection over and over again!
// -----------------------------------------------------------------------------
bool GetFile(TFile* &f , TString string){
    f = TFile::Open(string);
    
    if (f == NULL) {
        std::cout << "failed to get:\t" << string << "\tThis file might not exist in the file" << std::endl;
        return false;
    }
    else {
        return true;
    }
}
// -----------------------------------------------------------------------------
void GetTree(TFile* f, TTree* &T, TString string){
    T = (TTree*) f->Get(string);
    if (T == NULL) {
        std::cout << "\nfailed to get:\t" << string << "\tThis tree might not exist in the file, exiting...\n" << std::endl;
        exit(1);
    }
    else {
        return;
    }
}
// -----------------------------------------------------------------------------
double WrapPhi(double phi){
    double phi_wrapped{0};

    // >90 to 180
    if      (phi > 90   && phi <= 180) phi_wrapped = 180 - phi;
    
    // <0 to -90
    else if (phi >= -90  && phi < 0)   phi_wrapped = phi * -1;
    
    // <-90 to -180
    else if (phi >= -180 && phi < -90) phi_wrapped = 180 - (phi * -1);
    
    else phi_wrapped = phi;

    return phi_wrapped;
}
// -----------------------------------------------------------------------------
// Weight by a 1D histogram
double weight_1D( TFile *fweight, std::string variable, double value, std::string bkg_class, bool wrap){

    TH1D* hist;
    std::string histname;
    double weight = 1.0;
    char name[500];

    std::string wrap_phi = "";

    // If wrapping phi we make some modifications
    if (wrap) {

        // cosmic we dont wrap phi
        if (bkg_class == "cosmic"){
            wrap_phi = "";
        }
        else {
            wrap_phi = "wrapped_";
            value  = WrapPhi(value);
        }
        
        
    }
    
    if (bkg_class == "pi0_gamma") histname = "h_shower_" + variable + "_pi0_"        + wrap_phi + "ratio";
    if (bkg_class == "cosmic")    histname = "h_shower_" + variable + "_bkg_cosmic_" + wrap_phi + "ratio";
    if (bkg_class == "other_bkg") histname = "h_shower_" + variable + "_other_"      + wrap_phi + "ratio";

    snprintf(name, 500, "%s", histname.c_str() );
    
    hist = (TH1D*) fweight->Get(name);
    
    if (hist == NULL ) std::cout << "ERROR: Can't get Histogram!: " << name << std::endl;
    
    xbin   = hist->GetXaxis()->FindBin(value);
    
    weight = hist->GetBinContent(xbin);

    if (weight == 0) weight = 1.0;
    
    return weight;
}
// -----------------------------------------------------------------------------
double weight_2D( TFile *fweight, double value_x, double value_y, std::string bkg_class, bool wrap){

    TH2D* hist;
    std::string histname;
    double weight = 1.0;
    char name[500];

    std::string wrap_phi = "";

    // If wrapping phi we make some modifications
    if (wrap) {
        
        // cosmic we dont wrap phi
        if (bkg_class == "cosmic"){
            wrap_phi = "";
        }
        else {
            wrap_phi = "wrapped_";
            value_y  = WrapPhi(value_y);
        }
    }
    
    if (bkg_class == "pi0_gamma") histname = "h_ThetaBkg_pi0_Phi_"    + wrap_phi + "ratio";
    if (bkg_class == "cosmic")    histname = "h_ThetaBkg_cosmic_Phi_" + wrap_phi + "ratio";
    if (bkg_class == "other_bkg") histname = "h_ThetaBkg_pi0_Phi_"  + wrap_phi + "ratio";

    snprintf(name, 500, "%s", histname.c_str() );
    
    hist = (TH2D*) fweight->Get(name);
    
    if (hist == NULL ) std::cout << "ERROR: Can't get Histogram!: " << name << std::endl;
    
    xbin   = hist->GetXaxis()->FindBin(value_x);
    ybin   = hist->GetYaxis()->FindBin(value_y);
    
    weight = hist->GetBinContent(xbin, ybin);

    if (weight == 0) weight = 1.0;
    
    return weight;
}
// -----------------------------------------------------------------------------
void CompareWeightedDrawSpecs(TH1D* hist, std::string weighted_str, std::string variation, TLegend* legend, std::string histname){
    
    // ---------------------- 
    //    Axis Specifiers
    // ----------------------
    if (histname == "h_ldg_shwr_Phi" || histname == "h_shower_Phi"){
        hist->SetTitle(";Leading Shower #phi [degrees];Entries");
        // hist->GetYaxis()->SetRangeUser(0,250);
    }
    else if (histname == "h_ldg_shwr_Theta"|| histname == "h_shower_Theta"){
        hist->SetTitle(";Leading Shower #theta [degrees];Entries");
        // hist->GetYaxis()->SetRangeUser(0,200);

    }
    else if (histname == "h_ldg_shwr_Phi_wrapped" || histname == "h_shower_phi_wrapped"){
        hist->SetTitle(";Leading Shower #phi (wrapped) [degrees];Entries");
        hist->GetYaxis()->SetRangeUser(0,900);

    }
    else if (histname ==  "h_shower_phi_pi0"){
        hist->SetTitle("; Leading Shower Phi #pi^{0} Bkg [degrees];Entries");
        // hist->GetYaxis()->SetRangeUser(0,50);

    }
    else if (histname ==  "h_shower_phi_bkg_cosmic"){
        hist->SetTitle("; Leading Shower Phi cosmic Bkg [degrees];Entries");
        // hist->GetYaxis()->SetRangeUser(0,50);
    }
    else if (histname ==  "h_shower_phi_other"){
        hist->SetTitle("; Leading Shower Phi Other Bkg [degrees];Entries");
        hist->GetYaxis()->SetRangeUser(0,170);

    }
    else if (histname ==  "h_shower_phi_pi0_wrapped"){
        hist->SetTitle("; Leading Shower Phi Wrapped #pi^{0} Bkg [degrees];Entries");
        hist->GetYaxis()->SetRangeUser(0,600);

    }
    else if (histname ==  "h_shower_phi_bkg_cosmic_wrapped"){
        hist->SetTitle("; Leading Shower Phi Wrapped cosmic Bkg [degrees];Entries");
        // hist->GetYaxis()->SetRangeUser(0,40);

    }
    else if (histname ==  "h_shower_phi_other_wrapped"){
        hist->SetTitle("; Leading Shower Phi Wrapped Other Bkg [degrees];Entries");
        hist->GetYaxis()->SetRangeUser(0,250);

    }
    else if (histname ==  "h_shower_E_pi0"){
        hist->SetTitle("; Leading Shower Energy #pi^{0} Bkg [GeV];Entries");
        // hist->GetYaxis()->SetRangeUser(0,300);

    }
    else if (histname ==  "h_shower_E_bkg_cosmic"){
        hist->SetTitle("; Leading Shower Energy cosmic Bkg [GeV];Entries");
        // hist->GetYaxis()->SetRangeUser(0,10);

    }
    else if (histname ==  "h_shower_E_other"){
        hist->SetTitle("; Leading Shower Energy Other Bkg [GeV];Entries");
        // hist->GetYaxis()->SetRangeUser(0,200);

    }
    else if (histname ==  "h_shower_E"){
        hist->SetTitle("; Leading Shower Energy Bkg [GeV];Entries");
        hist->GetYaxis()->SetRangeUser(0,1000);

    }
    else if (histname ==  "h_shower_Theta_pi0"){
        hist->SetTitle("; Leading Shower Theta #pi^{0} Bkg [degrees];Entries");
        // hist->GetYaxis()->SetRangeUser(0,600);

    }
    else if (histname ==  "h_shower_Theta_bkg_cosmic"){
        hist->SetTitle("; Leading Shower Theta cosmic Bkg [degrees];Entries");
        // hist->GetYaxis()->SetRangeUser(0,40);

    }
    else if (histname ==  "h_shower_Theta_other"){
        hist->SetTitle("; Leading Shower Theta Other Bkg [degrees];Entries");
        // hist->GetYaxis()->SetRangeUser(0,250);

    }
    else return;

    std::string draw_spec = "hist,E, same";
    hist->SetOption("hist, E");

    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);
    gPad->SetLeftMargin(0.15);
    gPad->SetBottomMargin(0.12);


    if (variation == "BNBCV" || variation == "NuMICV"){
        hist->SetLineWidth(2);
        hist->SetLineStyle(1);

        if (weighted_str == "BNBWeighted_Variations"){
            hist->SetLineColor(kAzure-6);
            legend->AddEntry(hist, "Weighted BNB CV", "l");
        } 
        else{
            hist->SetLineColor(kBlack);
            legend->AddEntry(hist, "NuMI CV", "l");
        }

        
        hist->Draw(draw_spec.c_str());
    } 
    else if  (variation == "BNBwithDIC"         || variation == "NuMIwithDIC"){
        hist->SetLineWidth(2);
        hist->SetLineStyle(1);
        
        if (weighted_str == "BNBWeighted_Variations"){
            hist->SetLineColor(kMagenta+2);
            legend->AddEntry(hist, "Weighted BNB DIC", "l");
        } 
        else{
            hist->SetLineColor(kBlack);
            legend->AddEntry(hist, "NuMI DIC", "l");
        }
        
        hist->Draw(draw_spec.c_str());
    }
    else if  (variation == "BNBdeadSaturatedChannels" || variation == "NuMIdeadSaturatedChannels"){
        hist->SetLineWidth(2);
        hist->SetLineStyle(1);
    
        if (weighted_str == "BNBWeighted_Variations"){
            hist->SetLineColor(28);
            legend->AddEntry(hist, "Weighted BNB Dead  Sat. Chan.", "l");
        } 
        else{
            hist->SetLineColor(kBlack);
            legend->AddEntry(hist, "NuMI Dead Sat. Chan.", "l");
        }

        hist->Draw(draw_spec.c_str());
        
    }
    else if  (variation == "BNBLArG4BugFix"  || variation == "NuMILArG4BugFix"){
        
        hist->SetLineWidth(2);
        hist->SetLineStyle(1);
        hist->Draw(draw_spec.c_str());

        if (weighted_str == "BNBWeighted_Variations"){
            hist->SetLineColor(kSpring-7);
            legend->AddEntry(hist, "Weighted BNB LArG4BugFix", "l");
        } 
        else{
            hist->SetLineColor(kBlack);
            legend->AddEntry(hist, "NuMI LArG4BugFix", "l");
        }
    }
    else {
        std::cout << "Error! Could not match varations:\t" << variation << std::endl;
        return;
    }

}
// -----------------------------------------------------------------------------
void CompareWeightedHistograms(TFile *fnumi, std::vector<std::vector<TH1D*>> TH1D_hist_weighted){

    system("if [ ! -d \"plots/weighted_bnb/\" ]; then echo \"\nPlots folder does not exist... creating\"; mkdir -p plots/weighted_bnb/; fi");
    system("if [ ! -d \"plots_png/weighted_bnb/\" ]; then echo \"\nPlots folder does not exist... creating\"; mkdir -p plots_png/weighted_bnb/; fi");

    std::vector<std::string> variations     = {"NuMICV", "NuMILArG4BugFix", "NuMIwithDIC", "NuMIdeadSaturatedChannels"};
    std::vector<std::string> variations_BNB = {"BNBCV",  "BNBLArG4BugFix",  "BNBwithDIC",  "BNBdeadSaturatedChannels"};
    std::vector<std::string> variations_name= {"CV",        "LArG4BugFix",     "withDIC",     "deadSaturatedChannels"};

    std::vector<std::string> histnames = {
                                          "h_ldg_shwr_Phi",           "h_ldg_shwr_Phi_wrapped",          "h_ldg_shwr_Theta",
                                          "h_shower_phi_pi0",         "h_shower_phi_bkg_cosmic",         "h_shower_phi_other", "h_shower_E",
                                          "h_shower_phi_pi0_wrapped", "h_shower_phi_bkg_cosmic_wrapped", "h_shower_phi_other_wrapped",
                                          "h_shower_E_pi0",           "h_shower_E_bkg_cosmic",           "h_shower_E_other", 
                                          "h_shower_Theta_pi0",       "h_shower_Theta_bkg_cosmic",       "h_shower_Theta_other"};

    char name[500];

    for (unsigned int i = 0; i<variations.size(); i++){

        for (unsigned int k=0; k< histnames.size(); k++){

            TCanvas* c = new TCanvas();
            TLegend* legend = new TLegend(0.60, 0.80, 0.90, 0.89);
            legend->SetBorderSize(0);
            legend->SetFillStyle(0);

            TH1D *hist_NuMI; // Thea actual numi variation
            std::string histname_NuMI = variations.at(i) + "/" + histnames.at(k);
            snprintf(name, 500, "%s", histname_NuMI.c_str() );
            hist_NuMI = (TH1D*)fnumi->Get(name); 
            if (hist_NuMI == NULL ) std::cout << "ERROR: Can't get Histogram!: " << name << std::endl;

            CompareWeightedDrawSpecs(TH1D_hist_weighted.at(k).at(i), "BNBWeighted_Variations", variations_BNB.at(i), legend, histnames.at(k));
            CompareWeightedDrawSpecs(hist_NuMI, "", variations.at(i), legend, histnames.at(k)); 

            std::cout << "BNB Int: " << TH1D_hist_weighted.at(k).at(i)->Integral(0,-1) << "  NuMI Int: "<<  hist_NuMI->Integral(0, -1)<<  std::endl;
            
            legend->Draw();

            char Canvas_name[1000];
            snprintf(Canvas_name, 1000, "plots/weighted_bnb/%s_%s.pdf", histnames.at(k).c_str(), variations_name.at(i).c_str()); 
            c->Print(Canvas_name);
            c->Close();

        }

    }

}
// -----------------------------------------------------------------------------
void background_study(){

    // The input file
    TFile *file_in, *fweight, *fnumi;
     // Get the input file
    GetFile(file_in, "plots/variation_out_bnb_bkg.root");
    GetFile(fnumi, "plots/variation_out_numi_bkg.root");
    GetFile(fweight, "plots/variation_weights.root");

    std::vector<std::string> variations = {"BNBCV",  "BNBLArG4BugFix",  "BNBwithDIC",  "BNBdeadSaturatedChannels"};


    enum cv_weights {
        k_phi,
        k_theta,
        k_E,
        k_phi_wrapped,
        k_theta_phi,
        k_theta_phi_wrapped,
        k_cv_w_MAX
    };

    std::vector<std::vector<TH1D*>> TH1D_hist_weighted;
    enum TH1D_names_weighted{ 
                     kshower_phi_w,             kshower_phi_wrapped_w,            kshower_Theta_w, 
                     kshower_phi_pi0_w,         kshower_phi_bkg_cosmic_w,         kshower_phi_other_w,             kshower_E_w, 
                     kshower_phi_pi0_wrapped_w, kshower_phi_bkg_cosmic_wrapped_w, kshower_phi_other_wrapped_w,
                     kshower_E_pi0_w,           kshower_E_bkg_cosmic_w,           kshower_E_other_w,
                     kshower_Theta_pi0_w,       kshower_Theta_bkg_cosmic_w,       kshower_Theta_other_w,
                     kTH1D_names_weighted_MAX};
    
    


    std::vector<double> bins = { 0, 15, 30, 45, 60, 75, 90}; 
    double* bins_phi_wrapped = &bins[0];
    int n_bins = bins.size() - 1;

    TH1D_hist_weighted.resize(kTH1D_names_weighted_MAX);

    // Loop over the variations an make weighted histograms for each variation
    for (int p=0; p < TH1D_hist_weighted.size(); p++){
        TH1D_hist_weighted.at(p).resize(variations.size());
    }

    // A loop over the variations
    for (unsigned int k=0; k < TH1D_hist_weighted.at(0).size(); k++){
        // Leading shower
        TH1D_hist_weighted.at(kshower_phi_w).at(k)                     = new TH1D(Form("h_shower_Phi_%s_w", variations.at(k).c_str()),                    Form("h_shower_Phi %s", variations.at(k).c_str()),                   12, -180, 180);
        TH1D_hist_weighted.at(kshower_phi_pi0_w).at(k)                 = new TH1D(Form("h_shower_phi_pi0_%s_w", variations.at(k).c_str()),                Form("h_shower_phi_pi0 %s", variations.at(k).c_str()),               12 , -180 ,180); // Shower Phi pi0
        TH1D_hist_weighted.at(kshower_phi_bkg_cosmic_w).at(k)          = new TH1D(Form("h_shower_phi_bkg_cosmic_%s_w", variations.at(k).c_str()),         Form("h_shower_phi_bkg_cosmic %s", variations.at(k).c_str()),        12 , -180 ,180); // Shower Phi bkg electrons
        TH1D_hist_weighted.at(kshower_phi_other_w).at(k)               = new TH1D(Form("h_shower_phi_other_%s_w", variations.at(k).c_str()),              Form("h_shower_phi_other %s", variations.at(k).c_str()),             12 , -180 ,180); // Shower Phi
        
        TH1D_hist_weighted.at(kshower_phi_wrapped_w).at(k)             = new TH1D(Form("h_shower_phi_wrapped_%s_w", variations.at(k).c_str()),            Form("h_shower_phi_wrapped %s", variations.at(k).c_str()),           n_bins, bins_phi_wrapped);
        TH1D_hist_weighted.at(kshower_phi_pi0_wrapped_w).at(k)         = new TH1D(Form("h_shower_phi_pi0_wrapped_%s_w", variations.at(k).c_str()),        Form("h_shower_phi_pi0_wrapped %s", variations.at(k).c_str()),       n_bins, bins_phi_wrapped); // Shower Phi pi0 wrapped
        TH1D_hist_weighted.at(kshower_phi_bkg_cosmic_wrapped_w).at(k)  = new TH1D(Form("h_shower_phi_bkg_cosmic_wrapped_%s_w", variations.at(k).c_str()), Form("h_shower_phi_bkg_cosmic_wrapped %s", variations.at(k).c_str()),n_bins, bins_phi_wrapped); // Shower Phi bkg electrons wrapped
        TH1D_hist_weighted.at(kshower_phi_other_wrapped_w).at(k)       = new TH1D(Form("h_shower_phi_other_wrapped_%s_w", variations.at(k).c_str()),      Form("h_shower_phi_other_wrapped %s", variations.at(k).c_str()),     n_bins, bins_phi_wrapped); // Shower Phi wrapped
        
        TH1D_hist_weighted.at(kshower_E_pi0_w).at(k)                   = new TH1D(Form("h_shower_E_pi0_%s_w", variations.at(k).c_str()),                  Form("h_shower_E_pi0 %s", variations.at(k).c_str()),                 7 , 0, 3 ); // Shower E pi0
        TH1D_hist_weighted.at(kshower_E_bkg_cosmic_w).at(k)            = new TH1D(Form("h_shower_E_bkg_cosmic_%s_w", variations.at(k).c_str()),           Form("h_shower_E_bkg_cosmic %s", variations.at(k).c_str()),          7 , 0, 5 ); // Shower E bkg cosmic
        TH1D_hist_weighted.at(kshower_E_other_w).at(k)                 = new TH1D(Form("h_shower_E_other_%s_w", variations.at(k).c_str()),                Form("h_shower_E_other %s", variations.at(k).c_str()),               7 , 0, 3 ); // Shower E other
        TH1D_hist_weighted.at(kshower_E_w).at(k)                       = new TH1D(Form("h_shower_E_%s_w", variations.at(k).c_str()),                      Form("h_shower_E %s", variations.at(k).c_str()),                     7 , 0, 3 ); // Shower E
        
        TH1D_hist_weighted.at(kshower_Theta_w).at(k)                   = new TH1D(Form("h_shower_Theta_%s_w", variations.at(k).c_str()),                  Form("h_shower_Theta %s", variations.at(k).c_str()),                 12, 0, 180);
        TH1D_hist_weighted.at(kshower_Theta_pi0_w).at(k)               = new TH1D(Form("h_shower_Theta_pi0_%s_w", variations.at(k).c_str()),              Form("h_shower_Theta_pi0 %s", variations.at(k).c_str()),             12, 0, 180 ); // Shower Theta pi0
        TH1D_hist_weighted.at(kshower_Theta_bkg_cosmic_w).at(k)        = new TH1D(Form("h_shower_Theta_bkg_cosmic_%s_w", variations.at(k).c_str()),       Form("h_shower_Theta_bkg_cosmic %s", variations.at(k).c_str()),      12, 0, 180 ); // Shower Theta bkg cosmic
        TH1D_hist_weighted.at(kshower_Theta_other_w).at(k)             = new TH1D(Form("h_shower_Theta_other_%s_w", variations.at(k).c_str()),            Form("h_shower_Theta_other %s", variations.at(k).c_str()),           12, 0, 180 ); // Shower Theta other

    }

    TTree *selected_tree;
    double mc_Phi, mc_Theta, mc_Energy, mc_phi_wrapped;
    std::string *bkg_class = nullptr;
    std::vector<double> bnb_cv_weighted(k_cv_w_MAX,0.0);

    // Loop over the variations
    for (unsigned int j = 0; j < variations.size(); j++){
        std::cout << variations.at(j) << std::endl;

        double counter_tot{0}, counter_pi0{0}, counter_cosmic{0}, counter_other{0};
        double weight_1D_phi{0.0}, weight_1D_theta{0.0}, weight_1D_E{0.0}, weight_1D_phi_wrapped{0.0}, weight_2D_theta_phi{0.0}, weight_2D_theta_phi_wrapped{0.0};

        GetTree(file_in, selected_tree, Form("%s/selected_tree", variations.at(j).c_str()));
        selected_tree->SetBranchAddress("mc_Phi",    &mc_Phi);
        selected_tree->SetBranchAddress("mc_Theta",  &mc_Theta);
        selected_tree->SetBranchAddress("mc_Energy", &mc_Energy);
        selected_tree->SetBranchAddress("bkg_class", &bkg_class);
        

        double tree_total_entries = selected_tree->GetEntries();
        std::cout << "Total Events:         " << tree_total_entries << std::endl;

        for (int ievent = 0; ievent < tree_total_entries; ievent++){

            // Get the entry in the tree
            selected_tree->GetEntry(ievent);
            counter_tot++;
            mc_phi_wrapped = WrapPhi(mc_Phi);



            weight_1D_phi   += weight_1D(fweight, "phi" ,   mc_Phi,    *bkg_class, false); // Phi
            weight_1D_theta += weight_1D(fweight, "Theta" , mc_Theta,  *bkg_class, false); // Theta
            weight_1D_E     += weight_1D(fweight, "E" ,     mc_Energy, *bkg_class, false); // Energy
            weight_1D_phi_wrapped += weight_1D(fweight, "phi" ,   mc_Phi,    *bkg_class, true);    // Phi Wrapped
            weight_2D_theta_phi   += weight_2D(fweight, mc_Theta, mc_Phi, *bkg_class, false);      // Theta Phi
            weight_2D_theta_phi_wrapped += weight_2D(fweight, mc_Theta, mc_Phi, *bkg_class, true); // Theta Phi Wrapped

            double POT_Scaling = 8.2; // Aprox scale factor for the variations  -- hardcoded
                if (variations.at(j) == "BNBCV") {
                POT_Scaling = 1.0;
            }


            // Use this weight for making the weighted histograms -- switch as needed
            // double weight = weight_1D(fweight, "phi" ,   mc_Phi,    *bkg_class, false); // Phi
            double weight    = weight_2D(fweight, mc_Theta, mc_Phi, *bkg_class, false);      // Theta Phi

            weight = weight * POT_Scaling;
            
            if (*bkg_class == "pi0_gamma") {
                counter_pi0++;
                TH1D_hist_weighted.at(kshower_phi_pi0_w).at(j)        ->Fill(mc_Phi, weight);
                TH1D_hist_weighted.at(kshower_phi_pi0_wrapped_w).at(j)->Fill(mc_phi_wrapped, weight);
                TH1D_hist_weighted.at(kshower_E_pi0_w).at(j)          ->Fill(mc_Energy, weight);
                TH1D_hist_weighted.at(kshower_Theta_pi0_w).at(j)      ->Fill(mc_Theta, weight);
            }
        
            if (*bkg_class == "cosmic") {
                counter_cosmic++;
                TH1D_hist_weighted.at(kshower_phi_bkg_cosmic_w).at(j)        ->Fill(mc_Phi, weight);
                TH1D_hist_weighted.at(kshower_phi_bkg_cosmic_wrapped_w).at(j)->Fill(mc_phi_wrapped, weight);
                TH1D_hist_weighted.at(kshower_E_bkg_cosmic_w).at(j)          ->Fill(mc_Energy, weight);
                TH1D_hist_weighted.at(kshower_Theta_bkg_cosmic_w).at(j)      ->Fill(mc_Theta, weight);
            }
 
            if (*bkg_class == "other_bkg") {
                counter_other++;
                TH1D_hist_weighted.at(kshower_phi_other_w).at(j)        ->Fill(mc_Phi, weight);
                TH1D_hist_weighted.at(kshower_phi_other_wrapped_w).at(j)->Fill(mc_phi_wrapped, weight);
                TH1D_hist_weighted.at(kshower_E_other_w).at(j)          ->Fill(mc_Energy, weight);
                TH1D_hist_weighted.at(kshower_Theta_other_w).at(j)      ->Fill(mc_Theta, weight);

            }

            TH1D_hist_weighted.at(kshower_phi_w).at(j)        ->Fill(mc_Phi, weight);
            TH1D_hist_weighted.at(kshower_phi_wrapped_w).at(j)->Fill(mc_phi_wrapped, weight);
            TH1D_hist_weighted.at(kshower_E_w).at(j)            ->Fill(mc_Energy, weight);
            TH1D_hist_weighted.at(kshower_Theta_w).at(j)      ->Fill(mc_Theta, weight);

            // std::cout << "phi: "<< mc_Phi << "  Theta: " << mc_Theta << "  class: "<< *bkg_class << std::endl;

        } // End Event loop

        double scale_factor = 8.2;

        if (variations.at(j) == "BNBCV") {
            scale_factor = 1.0;
            bnb_cv_weighted.at(k_phi)   = weight_1D_phi;
            bnb_cv_weighted.at(k_theta) = weight_1D_theta;
            bnb_cv_weighted.at(k_E)     = weight_1D_E;
            bnb_cv_weighted.at(k_phi_wrapped)         = weight_1D_phi_wrapped;
            bnb_cv_weighted.at(k_theta_phi)           = weight_2D_theta_phi;
            bnb_cv_weighted.at(k_theta_phi_wrapped)   = weight_2D_theta_phi_wrapped;

        }
        
        std::cout << "Pi0 Counter                   --- " << counter_pi0     << std::endl;
        std::cout << "Cosmic Counter                --- " << counter_cosmic  << std::endl;
        std::cout << "Other Counter                 --- " << counter_other   << std::endl;
        std::cout << "RECO Background               --- " << counter_tot     << std::endl;
        std::cout << "Weighted 1D Phi               --- " << weight_1D_phi   << " : " << weight_1D_phi * scale_factor << " : " <<100 * (weight_1D_phi * scale_factor - bnb_cv_weighted.at(k_phi))/ bnb_cv_weighted.at(k_phi) << " \%"<< std::endl;
        std::cout << "Weighted 1D Theta             --- " << weight_1D_theta << " : " << weight_1D_theta * scale_factor << " : " <<100 * (weight_1D_theta * scale_factor - bnb_cv_weighted.at(k_theta))/ bnb_cv_weighted.at(k_theta) << " \%"<< std::endl;
        std::cout << "Weighted 1D E                 --- " << weight_1D_E     << " : " << weight_1D_E * scale_factor << " : " <<100 * (weight_1D_E * scale_factor - bnb_cv_weighted.at(k_E))/ bnb_cv_weighted.at(k_E) << " \%"<< std::endl;
        std::cout << "Weighted 1D Phi Wrapped       --- " << weight_1D_phi_wrapped   << " : " << weight_1D_phi_wrapped * scale_factor << " : " <<100 * (weight_1D_phi_wrapped * scale_factor - bnb_cv_weighted.at(k_phi_wrapped))/ bnb_cv_weighted.at(k_phi_wrapped) << " \%"<< std::endl;
        std::cout << "Weighted 2D Theta Phi         --- " << weight_2D_theta_phi   << " : " << weight_2D_theta_phi * scale_factor << " : " <<100 * (weight_2D_theta_phi * scale_factor - bnb_cv_weighted.at(k_theta_phi))/ bnb_cv_weighted.at(k_theta_phi) << " \%"<< std::endl;
        std::cout << "Weighted 2D Theta Phi Wrapped --- " << weight_2D_theta_phi_wrapped   << " : " << weight_2D_theta_phi_wrapped * scale_factor << " : " <<100 * (weight_2D_theta_phi_wrapped * scale_factor - bnb_cv_weighted.at(k_theta_phi_wrapped))/ bnb_cv_weighted.at(k_theta_phi_wrapped) << " \%"<< std::endl;
        std::cout << std::endl;

        selected_tree->Reset();
    }

    // Make the bnb numi comparison plots
    CompareWeightedHistograms(fnumi, TH1D_hist_weighted);

}
// -----------------------------------------------------------------------------
