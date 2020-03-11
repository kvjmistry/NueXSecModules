// Root script to compare the variation samples to the central value

bool GetHist(TFile* f, TH1D* &h, TString string){
	h = (TH1D*) f->Get(string);
	if (h == NULL) {
		std::cout << "\nfailed to get:\t" << string << "\tThis histogram might not exist in the file\n" << std::endl;
		return false;
	}
	else {
		return true;
	}
}
// ------------------------------------------------------------------------------------------------------------
bool GetHist(TFile* f, TH2D* &h, TString string){
	h = (TH2D*) f->Get(string);
	if (h == NULL) {
		std::cout << "\nfailed to get:\t" << string << "\tThis histogram might not exist in the file\n" << std::endl;
		return false;
	}
	else {
		return true;
	}
}
// ------------------------------------------------------------------------------------------------------------
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
// ------------------------------------------------------------------------------------------------------------
void compare_variation_samples(){

    TFile *f_bnb, *f_numi, *f_weights;

    bool boolfile  = GetFile(f_bnb ,"./plots/variation_out_bnb_bkg.root");
    if (boolfile == false) gSystem->Exit(0);

    boolfile  = GetFile(f_numi ,"./plots/variation_out_numi_bkg.root");
    if (boolfile == false) gSystem->Exit(0);

    boolfile  = GetFile(f_weights ,"./plots/variation_weights.root");
    if (boolfile == false) gSystem->Exit(0);


    TH1D *h_phi_dic_bnb, *h_phi_dic_numi, *h_phi_cv_ratio, *h_phi_larg4_bnb, *h_phi_larg4_numi, *h_phi_dsc_bnb, *h_phi_dsc_numi;

    const char* plot = "h_ldg_shwr_Phi";

    boolhist = GetHist(f_bnb, h_phi_dic_bnb,     Form("BNBwithDIC/%s", plot)); if (boolhist == false) gSystem->Exit(0);
    boolhist = GetHist(f_numi, h_phi_dic_numi,   Form("NuMIwithDIC/%s", plot)); if (boolhist == false) gSystem->Exit(0);
   
    boolhist = GetHist(f_bnb, h_phi_larg4_bnb,     Form("BNBLArG4BugFix/%s", plot)); if (boolhist == false) gSystem->Exit(0);
    boolhist = GetHist(f_numi, h_phi_larg4_numi,   Form("NuMILArG4BugFix/%s", plot)); if (boolhist == false) gSystem->Exit(0);
    
    boolhist = GetHist(f_bnb, h_phi_dsc_bnb,     Form("BNBdeadSaturatedChannels/%s", plot)); if (boolhist == false) gSystem->Exit(0);
    boolhist = GetHist(f_numi, h_phi_dsc_numi,   Form("NuMIdeadSaturatedChannels/%s", plot)); if (boolhist == false) gSystem->Exit(0);

    boolhist = GetHist(f_weights, h_phi_cv_ratio, Form("%s_ratio",plot)); if (boolhist == false) gSystem->Exit(0);


    TH1D* hist_divide = (TH1D*) h_phi_dic_numi->Clone("h_phi_dic_numi_clone");
    hist_divide->Sumw2();
    hist_divide->Divide(h_phi_dic_bnb);
    hist_divide->SetOption("E");

    TH1D* hist_divide_larg4 = (TH1D*) h_phi_larg4_numi->Clone("h_phi_larg4_numi_clone");
    hist_divide_larg4->Sumw2();
    hist_divide_larg4->Divide(h_phi_larg4_bnb);
    hist_divide_larg4->SetOption("E");
    hist_divide_larg4->SetLineColor(kGreen+1);

    TH1D* hist_divide_dsc = (TH1D*) h_phi_dsc_numi->Clone("h_phi_dsc_numi_clone");
    hist_divide_dsc->Sumw2();
    hist_divide_dsc->Divide(h_phi_larg4_bnb);
    hist_divide_dsc->SetOption("E");
    hist_divide_dsc->SetLineColor(42);

    TCanvas* c = new TCanvas();
    hist_divide->Draw();

    h_phi_cv_ratio->SetLineColor(kAzure+1);
    h_phi_cv_ratio->Draw("same,E");
    hist_divide_larg4->Draw("same,E");
    hist_divide_dsc->Draw("same,E");


    
    const char* plot2 = "h_ldg_shwr_dEdx_WPlane_precut";
    // const char* plot2 = "h_shwr_hit_threshold_precut";
    // const char* plot2 = "h_shwr_hit_threshold_collection_precut";

    TH1D *h_dedx_numi, *h_dedx_bnb; 
    boolhist = GetHist(f_bnb, h_dedx_bnb,     Form("BNBCV/%s", plot2)); if (boolhist == false) gSystem->Exit(0);
    boolhist = GetHist(f_numi, h_dedx_numi,   Form("NuMICV/%s", plot2)); if (boolhist == false) gSystem->Exit(0);

    TCanvas* c2 = new TCanvas();
    TH1D* hist_divide2 = (TH1D*) h_dedx_numi->Clone("h_dedx_numi_clone");
    hist_divide2->Sumw2();
    hist_divide2->Divide(h_dedx_bnb);
    hist_divide2->SetOption("E");
    hist_divide2->Draw();


}