// Root script to weight the NuMI CV cosmics by the rate difference between overlay and full MC
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
void weight_cosmics(){

    gStyle->SetOptStat(0); // say no to stats box

    // The input file
    TFile *fnumi;
     // Get the input file
    GetFile(fnumi, "plots/variation_out_numi_bkg.root");

    // std::vector<std::string> variations = {"BNBCV",  "BNBLArG4BugFix",  "BNBwithDIC",  "BNBdeadSaturatedChannels"};
    std::vector<std::string> variations = {
                                        "NuMICV"};


    TTree *selected_tree;
    double mc_Phi, mc_Theta, mc_Energy, mc_phi_wrapped;
    std::string *bkg_class = nullptr;

    double counter_tot = 0.0, counter_pi0 = 0.0, counter_cosmic = 0.0, counter_other = 0.0;

    // Loop over the variations
    for (unsigned int j = 0; j < variations.size(); j++){
        std::cout << variations.at(j) << std::endl;

        counter_tot = 0.0, counter_pi0 = 0.0, counter_cosmic = 0.0, counter_other = 0.0;
        
        GetTree(fnumi, selected_tree, Form("%s/selected_tree", variations.at(j).c_str()));
        selected_tree->SetBranchAddress("mc_Phi",    &mc_Phi);
        selected_tree->SetBranchAddress("mc_Theta",  &mc_Theta);
        selected_tree->SetBranchAddress("mc_Energy", &mc_Energy);
        selected_tree->SetBranchAddress("bkg_class", &bkg_class);
        

        double tree_total_entries = selected_tree->GetEntries();
        std::cout << "Total Events:         " << tree_total_entries << std::endl;

        double weight_cosmic = 1.0;

        for (int ievent = 0; ievent < tree_total_entries; ievent++){

            // Get the entry in the tree
            selected_tree->GetEntry(ievent);
            counter_tot++;

            if (*bkg_class == "cosmic") weight_cosmic   += 0.6; // cosmic
            else weight_cosmic += 1.0;

            if (*bkg_class == "pi0_gamma") {
                counter_pi0++;
                
            }
        
            if (*bkg_class == "cosmic") {
                counter_cosmic++;
                
            }
 
            if (*bkg_class == "other_bkg") {
                counter_other++;
                
            }
            
            std::cout << "phi: "<< mc_Phi << "  Theta: " << mc_Theta << "  class: "<< *bkg_class << std::endl;

        } // End Event loop

        std::cout << "Pi0 Counter                   --- " << counter_pi0     << std::endl;
        std::cout << "Cosmic Counter                --- " << counter_cosmic  << std::endl;
        std::cout << "Other Counter                 --- " << counter_other   << std::endl;
        std::cout << "RECO Background               --- " << counter_tot     << std::endl;
        std::cout << "Weighted Cosmic               --- " << weight_cosmic   << " : " << weight_cosmic << " : " <<100 * (weight_cosmic- counter_tot)/counter_tot << " \%"<< std::endl;
       
        std::cout << std::endl;

        selected_tree->Reset();
    }

}
// -----------------------------------------------------------------------------
