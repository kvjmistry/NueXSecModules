#ifndef SELECTION_FUNCTIONS_h
#define SELECTION_FUNCTIONS_h

#include "../xsecAna/TpcObjectContainer.h"
#include "../xsecAna/ParticleContainer.h"

#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TEfficiency.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"
#include "THStack.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TPad.h"
#include "TMarker.h"
#include "TVector3.h"

#include <iostream>
#include <vector>

#include "../xsecAna/LinkDef.h"




class selection_functions {

public:

selection_functions()=default;

//***************************************************************************
void PostCutsdEdx(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                  std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                  std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                  TH1D * h_dedx_cuts_nue_cc,
                  TH1D * h_dedx_cuts_nue_cc_mixed,
                  TH1D * h_dedx_cuts_nue_cc_out_fv,
                  TH1D * h_dedx_cuts_numu_cc,
                  TH1D * h_dedx_cuts_nc,
                  TH1D * h_dedx_cuts_cosmic,
                  TH1D * h_dedx_cuts_nc_pi0,
                  TH1D * h_dedx_cuts_numu_cc_mixed,
                  TH1D * h_dedx_cuts_other_mixed,
                  TH1D * h_dedx_cuts_unmatched     );
void PostCutsdEdxInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                        std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                        TH1D * h_dedx_cuts_intime);
//***************************************************************************
void PostCutsdEdxTrueParticle(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                              std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                              std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                              TH1D * h_dedx_cuts_electron,
                              TH1D * h_dedx_cuts_photon,
                              TH1D * h_dedx_cuts_proton,
                              TH1D * h_dedx_cuts_pion,
                              TH1D * h_dedx_cuts_muon,
                              TH1D * h_dedx_cuts_kaon,
                              TH1D * h_dedx_cuts_neutron,
                              TH1D * h_dedx_cuts_unmatched);
void PostCutsdEdxTrueParticleInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                    std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                    TH1 * h_dedx_cuts_ext_unmatched);
void PostCutsdEdxHitsTrueParticle(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                  std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                  std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                                  TH2D * h_dedx_cuts_electron,
                                  TH2D * h_dedx_cuts_photon,
                                  TH2D * h_dedx_cuts_proton,
                                  TH2D * h_dedx_cuts_pion,
                                  TH2D * h_dedx_cuts_muon,
                                  TH2D * h_dedx_cuts_kaon,
                                  TH2D * h_dedx_cuts_neutron,
                                  TH2D * h_dedx_cuts_unmatched,
                                  TH2D * h_dedx_cuts_collection_electron,
                                  TH2D * h_dedx_cuts_collection_photon,
                                  TH2D * h_dedx_cuts_collection_proton,
                                  TH2D * h_dedx_cuts_collection_pion,
                                  TH2D * h_dedx_cuts_collection_muon,
                                  TH2D * h_dedx_cuts_collection_kaon,
                                  TH2D * h_dedx_cuts_collection_neutron,
                                  TH2D * h_dedx_cuts_collection_unmatched);
//***************************************************************************
void FillPostCutVector(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                       std::vector<std::pair<int, std::string> > * passed_tpco,
                       std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                       std::vector<std::tuple<int, int, double, double, double, std::string, std::string, int, int, double> > * post_cuts_v);
void FillPostCutVector(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                       std::vector<std::pair<int, std::string> > * passed_tpco,
                       std::vector<std::tuple<int, int, double, double, double, std::string, std::string, int, int, double> > * post_cuts_v);
//***************************************************************************
//***************************************************************************
void PrintPostCutVector(std::vector<std::tuple<int, int, double, double, double,
                                               std::string, std::string, int, int, double> > * post_cuts_v, bool _post_cuts_verbose);
//***************************************************************************
//***************************************************************************
void PostCutVectorPlots(std::vector<std::tuple<int, int, double, double, double, std::string, std::string, int, int, double> > * post_cuts_v,
                        bool _post_cuts_verbose, TH1 * post_cuts_num_showers_purity_qe,
                        TH1 * post_cuts_num_showers_purity_res,
                        TH1 * post_cuts_num_showers_purity_dis,
                        TH1 * post_cuts_num_showers_purity_coh,
                        TH1 * post_cuts_num_showers_purity_mec);
//***************************************************************************
//***************************************************************************
//this function just counts if at least 1 tpc object passes the cuts
bool ValidTPCObjects(std::vector<std::pair<int, std::string> > * passed_tpco);
//***************************************************************************
//***************************************************************************
void TabulateOriginsInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v, std::vector<std::pair<int, std::string> > * passed_tpco,
                           std::vector<int> * tabulated_origins_intime);
void TabulateOrigins(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v, std::vector<std::pair<int, std::string> > * passed_tpco,
                     std::vector<int> * tabulated_origins,
                     std::vector<std::pair<std::string, int> > * tpco_classifier_v);
//***************************************************************************
//***************************************************************************
void TotalOrigins(std::vector<int> * tabulated_origins, std::vector<int> * total_cut_origins);
void TotalOriginsInTime(std::vector<int> * tabulated_origins, std::vector<int> * total_cut_origins);
//***************************************************************************
//***************************************************************************
//modify this so it takes a string of the cut name so I only pass it a few variable at a time,
//then I can call this function several times later at the bottom
static void PrintInfo(int mc_nue_cc_counter, std::vector<int> * counter_v, int intime_counter,
                      double intime_scale_factor, double data_scale_factor, std::string cut_name);
//***************************************************************************
//***************************************************************************
static void ExportEfficiencyPurity(int mc_nue_cc_counter, std::vector<int> * counter_v, int counter_intime_cosmics,
                                   double intime_scale_factor, double data_scale_factor, std::string cut_name,
                                   std::vector<std::tuple< double, double, std::string> > * results_v);
//***************************************************************************
//***************************************************************************
static void PrintTopologyPurity(std::vector<int> * no_track, std::vector<int> * has_track,
                                std::vector<int> * _1_shwr, std::vector<int> * _2_shwr, std::vector<int> * _3_shwr, std::vector<int> * _4_shwr);
//***************************************************************************
//***************************************************************************
std::pair<std::string, int> TPCO_Classifier(xsecAna::TPCObjectContainer tpc_obj, bool has_pi0, bool true_in_tpc);
//***************************************************************************
//***************************************************************************
void FillTPCOClassV(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v, bool true_in_tpc, bool has_pi0,
                    std::vector<std::pair<std::string, int> > * tpco_classifier_v);
//***************************************************************************
//***************************************************************************
static double calcNumNucleons(double _x1, double _x2, double _y1,
                              double _y2, double _z1, double _z2);
//***************************************************************************
//***************************************************************************
static void calcXSec(double _x1, double _x2, double _y1,
                     double _y2, double _z1, double _z2,
                     double n_total, double n_bkg, double flux, double efficiency, std::vector<double>  * xsec_cc);
//***************************************************************************
//***************************************************************************
static void XSecWork(double final_counter, double final_counter_nue_cc, double final_counter_nue_bar_cc, double final_counter_nue_cc_mixed,
                     double final_counter_nue_cc_out_fv, double final_counter_cosmic, double final_counter_nc, double final_counter_numu_cc,
                     double final_counter_numu_cc_mixed, double final_counter_nc_pi0, double final_counter_unmatched,
                     double final_counter_other_mixed, double final_counter_intime,
                     double intime_scale_factor, double final_counter_data, double data_scale_factor,
                     std::vector<double> fv_boundary_v, double flux_nue, double flux_nue_bar,
                     std::vector<double> selected_energy_vector, double genie_xsec_nue, double genie_xsec_nue_bar,
                     const int total_mc_entries_inFV_nue, const int total_mc_entries_inFV_nue_bar);
//***************************************************************************
//***************************************************************************
static void xsec_plot(bool _verbose, double genie_xsec_nue, double genie_xsec_nue_bar, double xsec_nue, double average_energy, double stat_error);
//***************************************************************************
//***************************************************************************
void PostCutOpenAngle(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                      std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                      std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                      TH1D * h_leading_shower_open_angle_nue_cc, TH1D * h_leading_shower_open_angle_nue_cc_out_fv,
                      TH1D * h_leading_shower_open_angle_nue_cc_mixed,
                      TH1D * h_leading_shower_open_angle_numu_cc, TH1D * h_leading_shower_open_angle_nc,
                      TH1D * h_leading_shower_open_angle_cosmic, TH1D * h_leading_shower_open_angle_nc_pi0,
                      TH1D * h_leading_shower_open_angle_numu_cc_mixed, TH1D * h_leading_shower_open_angle_other_mixed,
                      TH1D * h_leading_shower_open_angle_unmatched);
void PostCutOpenAngleInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                            std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                            TH1D * h_leading_shower_open_angle_intime);
//***************************************************************************
//***************************************************************************
void PostCutOpenAngle1Shower(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                             std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                             std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                             TH1D * h_leading_shower_open_angle_nue_cc, TH1D * h_leading_shower_open_angle_nue_cc_out_fv,
                             TH1D * h_leading_shower_open_angle_nue_cc_mixed,
                             TH1D * h_leading_shower_open_angle_numu_cc, TH1D * h_leading_shower_open_angle_nc,
                             TH1D * h_leading_shower_open_angle_cosmic, TH1D * h_leading_shower_open_angle_nc_pi0,
                             TH1D * h_leading_shower_open_angle_numu_cc_mixed, TH1D * h_leading_shower_open_angle_other_mixed,
                             TH1D * h_leading_shower_open_angle_unmatched);
void PostCutOpenAngle1ShowerInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                   std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                   TH1D * h_leading_shower_open_angle_intime);
//***************************************************************************
//***************************************************************************
void PostCutOpenAngle2PlusShower(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                 std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                 std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                                 TH1D * h_leading_shower_open_angle_nue_cc, TH1D * h_leading_shower_open_angle_nue_cc_out_fv,
                                 TH1D * h_leading_shower_open_angle_nue_cc_mixed,
                                 TH1D * h_leading_shower_open_angle_numu_cc, TH1D * h_leading_shower_open_angle_nc,
                                 TH1D * h_leading_shower_open_angle_cosmic, TH1D * h_leading_shower_open_angle_nc_pi0,
                                 TH1D * h_leading_shower_open_angle_numu_cc_mixed, TH1D * h_leading_shower_open_angle_other_mixed,
                                 TH1D * h_leading_shower_open_angle_unmatched);
void PostCutOpenAngle2PlusShowerInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                       std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                       TH1D * h_leading_shower_open_angle_intime);
//***************************************************************************
//***************************************************************************
void PostCutTrkVtx(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v, std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                   std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                   TH1D * h_trk_vtx_dist_nue_cc, TH1D * h_trk_vtx_dist_nue_cc_out_fv,
                   TH1D * h_trk_vtx_dist_nue_cc_mixed,
                   TH1D * h_trk_vtx_dist_numu_cc, TH1D * h_trk_vtx_dist_nc,
                   TH1D * h_trk_vtx_dist_cosmic, TH1D * h_trk_vtx_dist_nc_pi0,
                   TH1D * h_trk_vtx_dist_numu_cc_mixed, TH1D * h_trk_vtx_dist_other_mixed,
                   TH1D * h_trk_vtx_dist_unmatched);
//***************************************************************************
//***************************************************************************
void PostCutTrkVtxInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                         std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose, TH1D * h_trk_vtx_dist_intime);
//***************************************************************************
//***************************************************************************
void TopologyPlots1(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                    std::vector<std::pair<int, std::string> > * passed_tpco,
                    std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                    TH2D * h_pfp_track_shower_nue_cc_qe,
                    TH2D * h_pfp_track_shower_nue_cc_out_fv,
                    TH2D * h_pfp_track_shower_nue_cc_res,
                    TH2D * h_pfp_track_shower_nue_cc_dis,
                    TH2D * h_pfp_track_shower_nue_cc_coh,
                    TH2D * h_pfp_track_shower_nue_cc_mec,
                    TH2D * h_pfp_track_shower_nc,
                    TH2D * h_pfp_track_shower_numu_cc_qe,
                    TH2D * h_pfp_track_shower_numu_cc_res,
                    TH2D * h_pfp_track_shower_numu_cc_dis,
                    TH2D * h_pfp_track_shower_numu_cc_coh,
                    TH2D * h_pfp_track_shower_numu_cc_mec,
                    TH2D * h_pfp_track_shower_nc_pi0,
                    TH2D * h_pfp_track_shower_nue_cc_mixed,
                    TH2D * h_pfp_track_shower_numu_cc_mixed,
                    TH2D * h_pfp_track_shower_cosmic,
                    TH2D * h_pfp_track_shower_other_mixed,
                    TH2D * h_pfp_track_shower_unmatched,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_qe,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_out_fv,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_res,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_dis,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_coh,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_mec,
                    TH2D * h_leading_shower_mc_pdg_nc,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_qe,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_res,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_dis,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_coh,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_mec,
                    TH2D * h_leading_shower_mc_pdg_nc_pi0,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_mixed,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_mixed,
                    TH2D * h_leading_shower_mc_pdg_cosmic,
                    TH2D * h_leading_shower_mc_pdg_other_mixed,
                    TH2D * h_leading_shower_mc_pdg_unmatched,
                    TH1D * h_pfp_track_nue_cc_qe,
                    TH1D * h_pfp_track_nue_cc_out_fv,
                    TH1D * h_pfp_track_nue_cc_res,
                    TH1D * h_pfp_track_nue_cc_dis,
                    TH1D * h_pfp_track_nue_cc_coh,
                    TH1D * h_pfp_track_nue_cc_mec,
                    TH1D * h_pfp_track_nc,
                    TH1D * h_pfp_track_numu_cc_qe,
                    TH1D * h_pfp_track_numu_cc_res,
                    TH1D * h_pfp_track_numu_cc_dis,
                    TH1D * h_pfp_track_numu_cc_coh,
                    TH1D * h_pfp_track_numu_cc_mec,
                    TH1D * h_pfp_track_nc_pi0,
                    TH1D * h_pfp_track_nue_cc_mixed,
                    TH1D * h_pfp_track_numu_cc_mixed,
                    TH1D * h_pfp_track_cosmic,
                    TH1D * h_pfp_track_other_mixed,
                    TH1D * h_pfp_track_unmatched,
                    TH1D * h_pfp_shower_nue_cc_qe,
                    TH1D * h_pfp_shower_nue_cc_out_fv,
                    TH1D * h_pfp_shower_nue_cc_res,
                    TH1D * h_pfp_shower_nue_cc_dis,
                    TH1D * h_pfp_shower_nue_cc_coh,
                    TH1D * h_pfp_shower_nue_cc_mec,
                    TH1D * h_pfp_shower_nc,
                    TH1D * h_pfp_shower_numu_cc_qe,
                    TH1D * h_pfp_shower_numu_cc_res,
                    TH1D * h_pfp_shower_numu_cc_dis,
                    TH1D * h_pfp_shower_numu_cc_coh,
                    TH1D * h_pfp_shower_numu_cc_mec,
                    TH1D * h_pfp_shower_nc_pi0,
                    TH1D * h_pfp_shower_nue_cc_mixed,
                    TH1D * h_pfp_shower_numu_cc_mixed,
                    TH1D * h_pfp_shower_cosmic,
                    TH1D * h_pfp_shower_other_mixed,
                    TH1D * h_pfp_shower_unmatched    );
//***************************************************************************
//***************************************************************************
void NumShowersOpenAngle(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                         std::vector<std::pair<int, std::string> > * passed_tpco,
                         std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                         TH1D * h_pfp_shower_open_angle_nue_cc_qe,
                         TH1D * h_pfp_shower_open_angle_nue_cc_out_fv,
                         TH1D * h_pfp_shower_open_angle_nue_cc_res,
                         TH1D * h_pfp_shower_open_angle_nue_cc_dis,
                         TH1D * h_pfp_shower_open_angle_nue_cc_coh,
                         TH1D * h_pfp_shower_open_angle_nue_cc_mec,
                         TH1D * h_pfp_shower_open_angle_nc,
                         TH1D * h_pfp_shower_open_angle_numu_cc_qe,
                         TH1D * h_pfp_shower_open_angle_numu_cc_res,
                         TH1D * h_pfp_shower_open_angle_numu_cc_dis,
                         TH1D * h_pfp_shower_open_angle_numu_cc_coh,
                         TH1D * h_pfp_shower_open_angle_numu_cc_mec,
                         TH1D * h_pfp_shower_open_angle_nc_pi0,
                         TH1D * h_pfp_shower_open_angle_nue_cc_mixed,
                         TH1D * h_pfp_shower_open_angle_numu_cc_mixed,
                         TH1D * h_pfp_shower_open_angle_cosmic,
                         TH1D * h_pfp_shower_open_angle_other_mixed,
                         TH1D * h_pfp_shower_open_angle_unmatched
                         );
void NumShowersOpenAngleInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                               std::vector<std::pair<int, std::string> > * passed_tpco, TH1D * h_pfp_shower_open_angle_intime);
//***************************************************************************
//***************************************************************************
void TopologyPlots2(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                    std::vector<std::pair<int, std::string> > * passed_tpco,
                    std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                    TH2D * h_pfp_track_shower_nue_cc_qe,
                    TH2D * h_pfp_track_shower_nue_cc_out_fv,
                    TH2D * h_pfp_track_shower_nue_cc_res,
                    TH2D * h_pfp_track_shower_nue_cc_dis,
                    TH2D * h_pfp_track_shower_nue_cc_coh,
                    TH2D * h_pfp_track_shower_nue_cc_mec,
                    TH2D * h_pfp_track_shower_nc,
                    TH2D * h_pfp_track_shower_numu_cc_qe,
                    TH2D * h_pfp_track_shower_numu_cc_res,
                    TH2D * h_pfp_track_shower_numu_cc_dis,
                    TH2D * h_pfp_track_shower_numu_cc_coh,
                    TH2D * h_pfp_track_shower_numu_cc_mec,
                    TH2D * h_pfp_track_shower_nc_pi0,
                    TH2D * h_pfp_track_shower_nue_cc_mixed,
                    TH2D * h_pfp_track_shower_numu_cc_mixed,
                    TH2D * h_pfp_track_shower_cosmic,
                    TH2D * h_pfp_track_shower_other_mixed,
                    TH2D * h_pfp_track_shower_unmatched,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_qe,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_out_fv,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_res,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_dis,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_coh,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_mec,
                    TH2D * h_leading_shower_mc_pdg_nc,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_qe,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_res,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_dis,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_coh,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_mec,
                    TH2D * h_leading_shower_mc_pdg_nc_pi0,
                    TH2D * h_leading_shower_mc_pdg_nue_cc_mixed,
                    TH2D * h_leading_shower_mc_pdg_numu_cc_mixed,
                    TH2D * h_leading_shower_mc_pdg_cosmic,
                    TH2D * h_leading_shower_mc_pdg_other_mixed,
                    TH2D * h_leading_shower_mc_pdg_unmatched,
                    TH1D * h_pfp_track_nue_cc_qe,
                    TH1D * h_pfp_track_nue_cc_out_fv,
                    TH1D * h_pfp_track_nue_cc_res,
                    TH1D * h_pfp_track_nue_cc_dis,
                    TH1D * h_pfp_track_nue_cc_coh,
                    TH1D * h_pfp_track_nue_cc_mec,
                    TH1D * h_pfp_track_nc,
                    TH1D * h_pfp_track_numu_cc_qe,
                    TH1D * h_pfp_track_numu_cc_res,
                    TH1D * h_pfp_track_numu_cc_dis,
                    TH1D * h_pfp_track_numu_cc_coh,
                    TH1D * h_pfp_track_numu_cc_mec,
                    TH1D * h_pfp_track_nc_pi0,
                    TH1D * h_pfp_track_nue_cc_mixed,
                    TH1D * h_pfp_track_numu_cc_mixed,
                    TH1D * h_pfp_track_cosmic,
                    TH1D * h_pfp_track_other_mixed,
                    TH1D * h_pfp_track_unmatched,
                    TH1D * h_pfp_shower_nue_cc_qe,
                    TH1D * h_pfp_shower_nue_cc_out_fv,
                    TH1D * h_pfp_shower_nue_cc_res,
                    TH1D * h_pfp_shower_nue_cc_dis,
                    TH1D * h_pfp_shower_nue_cc_coh,
                    TH1D * h_pfp_shower_nue_cc_mec,
                    TH1D * h_pfp_shower_nc,
                    TH1D * h_pfp_shower_numu_cc_qe,
                    TH1D * h_pfp_shower_numu_cc_res,
                    TH1D * h_pfp_shower_numu_cc_dis,
                    TH1D * h_pfp_shower_numu_cc_coh,
                    TH1D * h_pfp_shower_numu_cc_mec,
                    TH1D * h_pfp_shower_nc_pi0,
                    TH1D * h_pfp_shower_nue_cc_mixed,
                    TH1D * h_pfp_shower_numu_cc_mixed,
                    TH1D * h_pfp_shower_cosmic,
                    TH1D * h_pfp_shower_other_mixed,
                    TH1D * h_pfp_shower_unmatched    );
//***************************************************************************
//***************************************************************************
void PostCutsVtxFlash(std::vector< double > largest_flash_v, std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                      std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                      std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                      TH1D * h_vtx_flash_nue_cc, TH1D * h_vtx_flash_nue_cc_out_fv, TH1D * h_vtx_flash_nue_cc_mixed,
                      TH1D * h_vtx_flash_numu_cc, TH1D * h_vtx_flash_nc,
                      TH1D * h_vtx_flash_cosmic, TH1D * h_vtx_flash_nc_pi0,
                      TH1D * h_vtx_flash_numu_cc_mixed, TH1D * h_vtx_flash_other_mixed,
                      TH1D * h_vtx_flash_unmatched);
//***************************************************************************
//***************************************************************************
void PostCutsVtxFlashInTime(std::vector< double > largest_flash_v, std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                            std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose, TH1D * h_vtx_flash_intime);
//***************************************************************************
//***************************************************************************
void PostCutsShwrVtx(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                     std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                     std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                     TH1D * h_shwr_vtx_dist_nue_cc,
                     TH1D * h_shwr_vtx_dist_nue_cc_out_fv,
                     TH1D * h_shwr_vtx_dist_nue_cc_mixed,
                     TH1D * h_shwr_vtx_dist_numu_cc,
                     TH1D * h_shwr_vtx_dist_nc,
                     TH1D * h_shwr_vtx_dist_cosmic,
                     TH1D * h_shwr_vtx_dist_nc_pi0,
                     TH1D * h_shwr_vtx_dist_numu_cc_mixed,
                     TH1D * h_shwr_vtx_dist_other_mixed,
                     TH1D * h_shwr_vtx_dist_unmatched     );
//***************************************************************************
//***************************************************************************
void PostCutsShwrVtxInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                           std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose, TH1D * h_shwr_vtx_dist_intime);
//***************************************************************************
//***************************************************************************
void PostCutHitThreshold(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                         std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                         std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                         double mc_nu_energy, double mc_ele_energy,
                         TH2D * h_shwr_hits_nu_eng, TH2D * h_shwr_hits_ele_eng);
//***************************************************************************
//***************************************************************************
void TopologyEfficiency(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                        std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                        std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                        std::vector<int> * no_track, std::vector<int> * has_track,
                        std::vector<int> * _1_shwr, std::vector<int> * _2_shwr,
                        std::vector<int> * _3_shwr, std::vector<int> * _4_shwr);
//***************************************************************************
//***************************************************************************
void SequentialTrueEnergyPlots(int mc_nu_id, double mc_nu_vtx_x, double mc_nu_vtx_y, double mc_nu_vtx_z,
                               std::vector<double> fv_boundary_v,
                               std::vector<int> * tabulated_origins, double mc_nu_energy,
                               double mc_ele_energy, TH1D * h_selected_nu_energy, TH1D * h_selected_ele_energy);
//***************************************************************************
//***************************************************************************
void ChargeShare(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                 std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                 std::vector<std::pair<std::string, int> > * tpco_classifier_v, TH1D * h_charge_share_nue_cc_mixed);
//***************************************************************************
//***************************************************************************
void FlashTot0(std::vector< double> largest_flash_v, double mc_nu_time, int mc_nu_id, std::vector<int> * tabulated_origins,
               std::vector<double> fv_boundary_v, double vtxX, double vtxY, double vtxZ, TH1D * h_flash_t0_diff);
//***************************************************************************
//***************************************************************************
void dEdxVsOpenAngle(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                     std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                     std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                     TH2D * h_dedx_open_angle_nue_cc,
                     TH2D * h_dedx_open_angle_nue_cc_out_fv,
                     TH2D * h_dedx_open_angle_nue_cc_mixed,
                     TH2D * h_dedx_open_angle_numu_cc,
                     TH2D * h_dedx_open_angle_numu_cc_mixed,
                     TH2D * h_dedx_open_angle_nc,
                     TH2D * h_dedx_open_angle_nc_pi0,
                     TH2D * h_dedx_open_angle_cosmic,
                     TH2D * h_dedx_open_angle_other_mixed,
                     TH2D * h_dedx_open_angle_unmatched);
void dEdxVsOpenAngleInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                           std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose, TH2D * h_dedx_open_angle_intime);
//***************************************************************************
//***************************************************************************
void ShowerLengthvsHits(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                        std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                        std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                        TH2D * h_shwr_len_hits_nue_cc,
                        TH2D * h_shwr_len_hits_nue_cc_out_fv,
                        TH2D * h_shwr_len_hits_nue_cc_mixed,
                        TH2D * h_shwr_len_hits_numu_cc,
                        TH2D * h_shwr_len_hits_numu_cc_mixed,
                        TH2D * h_shwr_len_hits_nc,
                        TH2D * h_shwr_len_hits_nc_pi0,
                        TH2D * h_shwr_len_hits_cosmic,
                        TH2D * h_shwr_len_hits_other_mixed,
                        TH2D * h_shwr_len_hits_unmatched);
void ShowerLengthvsHitsInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                              std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                              TH2D * h_shwr_len_hits_intime);
//***************************************************************************
//***************************************************************************
void SecondaryShowersDist(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                          std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                          std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                          TH1D * h_second_shwr_dist_nue_cc,
                          TH1D * h_second_shwr_dist_nue_cc_out_fv,
                          TH1D * h_second_shwr_dist_nue_cc_mixed,
                          TH1D * h_second_shwr_dist_numu_cc,
                          TH1D * h_second_shwr_dist_numu_cc_mixed,
                          TH1D * h_second_shwr_dist_nc,
                          TH1D * h_second_shwr_dist_nc_pi0,
                          TH1D * h_second_shwr_dist_cosmic,
                          TH1D * h_second_shwr_dist_other_mixed,
                          TH1D * h_second_shwr_dist_unmatched);
void SecondaryShowersDistInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                TH1D * h_second_shwr_dist_intime);
//***************************************************************************
//***************************************************************************
void HitLengthRatio(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                    std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                    std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                    TH1D * h_hit_length_ratio_nue_cc,
                    TH1D * h_hit_length_ratio_nue_cc_out_fv,
                    TH1D * h_hit_length_ratio_nue_cc_mixed,
                    TH1D * h_hit_length_ratio_numu_cc,
                    TH1D * h_hit_length_ratio_numu_cc_mixed,
                    TH1D * h_hit_length_ratio_nc,
                    TH1D * h_hit_length_ratio_nc_pi0,
                    TH1D * h_hit_length_ratio_cosmic,
                    TH1D * h_hit_length_ratio_other_mixed,
                    TH1D * h_hit_length_ratio_unmatched);
void HitLengthRatioInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                          std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                          TH1D * h_hit_length_ratio_intime);
//***************************************************************************
//***************************************************************************
void TrackLength(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                 std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                 std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                 TH1D * h_trk_length_nue_cc,
                 TH1D * h_trk_length_nue_cc_out_fv,
                 TH1D * h_trk_length_nue_cc_mixed,
                 TH1D * h_trk_length_numu_cc,
                 TH1D * h_trk_length_numu_cc_mixed,
                 TH1D * h_trk_length_nc,
                 TH1D * h_trk_length_nc_pi0,
                 TH1D * h_trk_length_cosmic,
                 TH1D * h_trk_length_other_mixed,
                 TH1D * h_trk_length_unmatched);
//***************************************************************************
//***************************************************************************
void LongestTrackLength(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                        std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                        std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                        TH1D * h_trk_length_nue_cc,
                        TH1D * h_trk_length_nue_cc_out_fv,
                        TH1D * h_trk_length_nue_cc_mixed,
                        TH1D * h_trk_length_numu_cc,
                        TH1D * h_trk_length_numu_cc_mixed,
                        TH1D * h_trk_length_nc,
                        TH1D * h_trk_length_nc_pi0,
                        TH1D * h_trk_length_cosmic,
                        TH1D * h_trk_length_other_mixed,
                        TH1D * h_trk_length_unmatched);
//***************************************************************************
//***************************************************************************
void ShowerLength(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                  std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                  std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                  TH1D * h_shwr_length_nue_cc,
                  TH1D * h_shwr_length_nue_cc_out_fv,
                  TH1D * h_shwr_length_nue_cc_mixed,
                  TH1D * h_shwr_length_numu_cc,
                  TH1D * h_shwr_length_numu_cc_mixed,
                  TH1D * h_shwr_length_nc,
                  TH1D * h_shwr_length_nc_pi0,
                  TH1D * h_shwr_length_cosmic,
                  TH1D * h_shwr_length_other_mixed,
                  TH1D * h_shwr_length_unmatched);
//***************************************************************************
//***************************************************************************
void LongestShowerLength(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                         std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                         std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                         TH1D * h_shwr_length_nue_cc,
                         TH1D * h_shwr_length_nue_cc_out_fv,
                         TH1D * h_shwr_length_nue_cc_mixed,
                         TH1D * h_shwr_length_numu_cc,
                         TH1D * h_shwr_length_numu_cc_mixed,
                         TH1D * h_shwr_length_nc,
                         TH1D * h_shwr_length_nc_pi0,
                         TH1D * h_shwr_length_cosmic,
                         TH1D * h_shwr_length_other_mixed,
                         TH1D * h_shwr_length_unmatched);
//***************************************************************************
//***************************************************************************
void LeadingShowerLength(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                         std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                         std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                         TH1D * h_shwr_length_nue_cc,
                         TH1D * h_shwr_length_nue_cc_out_fv,
                         TH1D * h_shwr_length_nue_cc_mixed,
                         TH1D * h_shwr_length_numu_cc,
                         TH1D * h_shwr_length_numu_cc_mixed,
                         TH1D * h_shwr_length_nc,
                         TH1D * h_shwr_length_nc_pi0,
                         TH1D * h_shwr_length_cosmic,
                         TH1D * h_shwr_length_other_mixed,
                         TH1D * h_shwr_length_unmatched);
void LeadingShowerLengthInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                               std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                               TH1D * h_shwr_length_intime);
//***************************************************************************
//***************************************************************************
void LeadingShowerTrackLengths(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                               std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                               std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                               TH1D * h_shwr_trk_length_nue_cc,
                               TH1D * h_shwr_trk_length_nue_cc_out_fv,
                               TH1D * h_shwr_trk_length_nue_cc_mixed,
                               TH1D * h_shwr_trk_length_numu_cc,
                               TH1D * h_shwr_trk_length_numu_cc_mixed,
                               TH1D * h_shwr_trk_length_nc,
                               TH1D * h_shwr_trk_length_nc_pi0,
                               TH1D * h_shwr_trk_length_cosmic,
                               TH1D * h_shwr_trk_length_other_mixed,
                               TH1D * h_shwr_trk_length_unmatched);
void LeadingShowerTrackLengthsInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                     std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                     TH1D * h_shwr_trk_length_intime);
//***************************************************************************
//***************************************************************************
void LongestShowerTrackLengths(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                               std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                               std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                               TH1D * h_shwr_trk_length_nue_cc,
                               TH1D * h_shwr_trk_length_nue_cc_out_fv,
                               TH1D * h_shwr_trk_length_nue_cc_mixed,
                               TH1D * h_shwr_trk_length_numu_cc,
                               TH1D * h_shwr_trk_length_numu_cc_mixed,
                               TH1D * h_shwr_trk_length_nc,
                               TH1D * h_shwr_trk_length_nc_pi0,
                               TH1D * h_shwr_trk_length_cosmic,
                               TH1D * h_shwr_trk_length_other_mixed,
                               TH1D * h_shwr_trk_length_unmatched);
//***************************************************************************
//***************************************************************************
void PlaneHitsComparisonShower(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                               std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                               std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                               TH2D * h_collection_total_hits_shower_nue_cc,
                               TH2D * h_collection_total_hits_shower_nue_cc_out_fv,
                               TH2D * h_collection_total_hits_shower_nue_cc_mixed,
                               TH2D * h_collection_total_hits_shower_numu_cc,
                               TH2D * h_collection_total_hits_shower_numu_cc_mixed,
                               TH2D * h_collection_total_hits_shower_nc,
                               TH2D * h_collection_total_hits_shower_nc_pi0,
                               TH2D * h_collection_total_hits_shower_cosmic,
                               TH2D * h_collection_total_hits_shower_other_mixed,
                               TH2D * h_collection_total_hits_shower_unmatched);
void PlaneHitsComparisonShowerInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                     std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                     TH2D * h_collection_total_hits_shower_intime);
//***************************************************************************
//***************************************************************************
void PlaneHitsComparisonLeadingShower(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                      std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                      std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                                      TH2D * h_collection_total_hits_shower_nue_cc,
                                      TH2D * h_collection_total_hits_shower_nue_cc_out_fv,
                                      TH2D * h_collection_total_hits_shower_nue_cc_mixed,
                                      TH2D * h_collection_total_hits_shower_numu_cc,
                                      TH2D * h_collection_total_hits_shower_numu_cc_mixed,
                                      TH2D * h_collection_total_hits_shower_nc,
                                      TH2D * h_collection_total_hits_shower_nc_pi0,
                                      TH2D * h_collection_total_hits_shower_cosmic,
                                      TH2D * h_collection_total_hits_shower_other_mixed,
                                      TH2D * h_collection_total_hits_shower_unmatched);
void PlaneHitsComparisonLeadingShowerInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                            std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                            TH2D * h_collection_total_hits_shower_intime);
//***************************************************************************
//***************************************************************************
void PlaneHitsComparisonTrack(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                              std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                              std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                              TH2D * h_collection_total_hits_track_nue_cc,
                              TH2D * h_collection_total_hits_track_nue_cc_out_fv,
                              TH2D * h_collection_total_hits_track_nue_cc_mixed,
                              TH2D * h_collection_total_hits_track_numu_cc,
                              TH2D * h_collection_total_hits_track_numu_cc_mixed,
                              TH2D * h_collection_total_hits_track_nc,
                              TH2D * h_collection_total_hits_track_nc_pi0,
                              TH2D * h_collection_total_hits_track_cosmic,
                              TH2D * h_collection_total_hits_track_other_mixed,
                              TH2D * h_collection_total_hits_track_unmatched);
void PlaneHitsComparisonTrackInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                    std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                    TH2D * h_collection_total_hits_track_intime);
//***************************************************************************
//***************************************************************************
void HitsPlots1D(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                 std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                 std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                 TH1D * h_collection_hits_track_nue_cc,
                 TH1D * h_collection_hits_track_nue_cc_out_fv,
                 TH1D * h_collection_hits_track_nue_cc_mixed,
                 TH1D * h_collection_hits_track_numu_cc,
                 TH1D * h_collection_hits_track_numu_cc_mixed,
                 TH1D * h_collection_hits_track_nc,
                 TH1D * h_collection_hits_track_nc_pi0,
                 TH1D * h_collection_hits_track_cosmic,
                 TH1D * h_collection_hits_track_other_mixed,
                 TH1D * h_collection_hits_track_unmatched,
                 TH1D * h_collection_hits_shower_nue_cc,
                 TH1D * h_collection_hits_shower_nue_cc_out_fv,
                 TH1D * h_collection_hits_shower_nue_cc_mixed,
                 TH1D * h_collection_hits_shower_numu_cc,
                 TH1D * h_collection_hits_shower_numu_cc_mixed,
                 TH1D * h_collection_hits_shower_nc,
                 TH1D * h_collection_hits_shower_nc_pi0,
                 TH1D * h_collection_hits_shower_cosmic,
                 TH1D * h_collection_hits_shower_other_mixed,
                 TH1D * h_collection_hits_shower_unmatched,
                 TH1D * h_collection_hits_leading_shower_nue_cc,
                 TH1D * h_collection_hits_leading_shower_nue_cc_out_fv,
                 TH1D * h_collection_hits_leading_shower_nue_cc_mixed,
                 TH1D * h_collection_hits_leading_shower_numu_cc,
                 TH1D * h_collection_hits_leading_shower_numu_cc_mixed,
                 TH1D * h_collection_hits_leading_shower_nc,
                 TH1D * h_collection_hits_leading_shower_nc_pi0,
                 TH1D * h_collection_hits_leading_shower_cosmic,
                 TH1D * h_collection_hits_leading_shower_other_mixed,
                 TH1D * h_collection_hits_leading_shower_unmatched,
                 TH1D * h_total_hits_leading_shower_nue_cc,
                 TH1D * h_total_hits_leading_shower_nue_cc_out_fv,
                 TH1D * h_total_hits_leading_shower_nue_cc_mixed,
                 TH1D * h_total_hits_leading_shower_numu_cc,
                 TH1D * h_total_hits_leading_shower_numu_cc_mixed,
                 TH1D * h_total_hits_leading_shower_nc,
                 TH1D * h_total_hits_leading_shower_nc_pi0,
                 TH1D * h_total_hits_leading_shower_cosmic,
                 TH1D * h_total_hits_leading_shower_other_mixed,
                 TH1D * h_total_hits_leading_shower_unmatched);
void HitsPlots1DInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                       std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                       TH1D * h_collection_hits_track_intime,
                       TH1D * h_collection_hits_shower_intime,
                       TH1D * h_collection_hits_leading_shower_intime,
                       TH1D * h_total_hits_leading_shower_intime);
//***************************************************************************
//***************************************************************************
void EnergyHits(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                std::vector<std::pair<std::string, int> > * tpco_classifier_v, double mc_nu_energy, double mc_ele_energy,
                TH2D * h_ele_eng_total_hits, TH2D * h_ele_eng_colleciton_hits, TH2D * h_nu_eng_total_hits, TH2D * h_nu_eng_collection_hits);
//***************************************************************************
//***************************************************************************
int MapFailureCutToString(const std::string failure_cut);
//***************************************************************************
//***************************************************************************
void FailureReason(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                   std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                   std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                   TH1D * h_failure_reason_nue_cc,
                   TH1D * h_failure_reason_nue_cc_out_fv,
                   TH1D * h_failure_reason_nue_cc_mixed,
                   TH1D * h_failure_reason_numu_cc,
                   TH1D * h_failure_reason_numu_cc_mixed,
                   TH1D * h_failure_reason_nc,
                   TH1D * h_failure_reason_nc_pi0,
                   TH1D * h_failure_reason_cosmic,
                   TH1D * h_failure_reason_other_mixed,
                   TH1D * h_failure_reason_unmatched);
//***************************************************************************
//***************************************************************************
void LeadingCosTheta(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                     std::vector<std::pair<int, std::string> > * passed_tpco,
                     const double theta_translation, const double phi_translation, bool _verbose,
                     std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                     TH1D * h_ele_cos_theta_nue_cc,
                     TH1D * h_ele_cos_theta_nue_cc_out_fv,
                     TH1D * h_ele_cos_theta_nue_cc_mixed,
                     TH1D * h_ele_cos_theta_numu_cc,
                     TH1D * h_ele_cos_theta_numu_cc_mixed,
                     TH1D * h_ele_cos_theta_nc,
                     TH1D * h_ele_cos_theta_nc_pi0,
                     TH1D * h_ele_cos_theta_cosmic,
                     TH1D * h_ele_cos_theta_other_mixed,
                     TH1D * h_ele_cos_theta_unmatched);
void LeadingCosThetaInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                           std::vector<std::pair<int, std::string> > * passed_tpco,
                           const double theta_translation, const double phi_translation, bool _verbose, TH1D * h_ele_cos_theta_intime);
//***************************************************************************
//***************************************************************************
void LeadingMomentum(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                     std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                     std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                     TH1D * h_ele_pfp_momentum_nue_cc,
                     TH1D * h_ele_pfp_momentum_nue_cc_out_fv,
                     TH1D * h_ele_pfp_momentum_nue_cc_mixed,
                     TH1D * h_ele_pfp_momentum_numu_cc,
                     TH1D * h_ele_pfp_momentum_numu_cc_mixed,
                     TH1D * h_ele_pfp_momentum_nc,
                     TH1D * h_ele_pfp_momentum_nc_pi0,
                     TH1D * h_ele_pfp_momentum_cosmic,
                     TH1D * h_ele_pfp_momentum_other_mixed,
                     TH1D * h_ele_pfp_momentum_unmatched);
void LeadingMomentumInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                           std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose, TH1D * h_ele_pfp_momentum_intime);
//***************************************************************************
//***************************************************************************
void PostCutsLeadingMomentumThetaSlice(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                       std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                       std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                                       TH1D * h_ele_momentum_1_nue_cc,
                                       TH1D * h_ele_momentum_1_nue_cc_out_fv,
                                       TH1D * h_ele_momentum_1_nue_cc_mixed,
                                       TH1D * h_ele_momentum_1_numu_cc,
                                       TH1D * h_ele_momentum_1_numu_cc_mixed,
                                       TH1D * h_ele_momentum_1_nc,
                                       TH1D * h_ele_momentum_1_nc_pi0,
                                       TH1D * h_ele_momentum_1_cosmic,
                                       TH1D * h_ele_momentum_1_other_mixed,
                                       TH1D * h_ele_momentum_1_unmatched,
                                       TH1D * h_ele_momentum_2_nue_cc,
                                       TH1D * h_ele_momentum_2_nue_cc_out_fv,
                                       TH1D * h_ele_momentum_2_nue_cc_mixed,
                                       TH1D * h_ele_momentum_2_numu_cc,
                                       TH1D * h_ele_momentum_2_numu_cc_mixed,
                                       TH1D * h_ele_momentum_2_nc,
                                       TH1D * h_ele_momentum_2_nc_pi0,
                                       TH1D * h_ele_momentum_2_cosmic,
                                       TH1D * h_ele_momentum_2_other_mixed,
                                       TH1D * h_ele_momentum_2_unmatched,
                                       TH1D * h_ele_momentum_3_nue_cc,
                                       TH1D * h_ele_momentum_3_nue_cc_out_fv,
                                       TH1D * h_ele_momentum_3_nue_cc_mixed,
                                       TH1D * h_ele_momentum_3_numu_cc,
                                       TH1D * h_ele_momentum_3_numu_cc_mixed,
                                       TH1D * h_ele_momentum_3_nc,
                                       TH1D * h_ele_momentum_3_nc_pi0,
                                       TH1D * h_ele_momentum_3_cosmic,
                                       TH1D * h_ele_momentum_3_other_mixed,
                                       TH1D * h_ele_momentum_3_unmatched);
void PostCutsLeadingMomentumThetaSliceInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                             std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                             TH1D * h_ele_momentum_1_intime,
                                             TH1D * h_ele_momentum_2_intime,
                                             TH1D * h_ele_momentum_3_intime);
//***************************************************************************
//***************************************************************************
void LeadingPhi(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                TH1D * h_ele_pfp_phi_nue_cc,
                TH1D * h_ele_pfp_phi_nue_cc_out_fv,
                TH1D * h_ele_pfp_phi_nue_cc_mixed,
                TH1D * h_ele_pfp_phi_numu_cc,
                TH1D * h_ele_pfp_phi_numu_cc_mixed,
                TH1D * h_ele_pfp_phi_nc,
                TH1D * h_ele_pfp_phi_nc_pi0,
                TH1D * h_ele_pfp_phi_cosmic,
                TH1D * h_ele_pfp_phi_other_mixed,
                TH1D * h_ele_pfp_phi_unmatched);
void LeadingPhiInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                      std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                      TH1D * h_ele_pfp_phi_intime);
//***************************************************************************
//***************************************************************************
void LeadingTheta(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                  std::vector<std::pair<int, std::string> > * passed_tpco,
                  const double theta_translation, const double phi_translation, bool _verbose,
                  std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                  TH1D * h_ele_pfp_theta_nue_cc,
                  TH1D * h_ele_pfp_theta_nue_cc_out_fv,
                  TH1D * h_ele_pfp_theta_nue_cc_mixed,
                  TH1D * h_ele_pfp_theta_numu_cc,
                  TH1D * h_ele_pfp_theta_numu_cc_mixed,
                  TH1D * h_ele_pfp_theta_nc,
                  TH1D * h_ele_pfp_theta_nc_pi0,
                  TH1D * h_ele_pfp_theta_cosmic,
                  TH1D * h_ele_pfp_theta_other_mixed,
                  TH1D * h_ele_pfp_theta_unmatched);
void LeadingThetaInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                        std::vector<std::pair<int, std::string> > * passed_tpco,
                        const double theta_translation, const double phi_translation, bool _verbose,
                        TH1D * h_ele_pfp_theta_intime);
//***************************************************************************
//***************************************************************************
void Leading1Shwr2Shwr(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                       std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                       std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                       TH1D * h_leading_shwr_length_1shwr_nue_cc,
                       TH1D * h_leading_shwr_length_1shwr_nue_cc_out_fv,
                       TH1D * h_leading_shwr_length_1shwr_nue_cc_mixed,
                       TH1D * h_leading_shwr_length_1shwr_numu_cc,
                       TH1D * h_leading_shwr_length_1shwr_numu_cc_mixed,
                       TH1D * h_leading_shwr_length_1shwr_nc,
                       TH1D * h_leading_shwr_length_1shwr_nc_pi0,
                       TH1D * h_leading_shwr_length_1shwr_cosmic,
                       TH1D * h_leading_shwr_length_1shwr_other_mixed,
                       TH1D * h_leading_shwr_length_1shwr_unmatched,
                       TH1D * h_leading_shwr_length_2shwr_nue_cc,
                       TH1D * h_leading_shwr_length_2shwr_nue_cc_out_fv,
                       TH1D * h_leading_shwr_length_2shwr_nue_cc_mixed,
                       TH1D * h_leading_shwr_length_2shwr_numu_cc,
                       TH1D * h_leading_shwr_length_2shwr_numu_cc_mixed,
                       TH1D * h_leading_shwr_length_2shwr_nc,
                       TH1D * h_leading_shwr_length_2shwr_nc_pi0,
                       TH1D * h_leading_shwr_length_2shwr_cosmic,
                       TH1D * h_leading_shwr_length_2shwr_other_mixed,
                       TH1D * h_leading_shwr_length_2shwr_unmatched,
                       TH1D * h_leading_shwr_hits_1shwr_nue_cc,
                       TH1D * h_leading_shwr_hits_1shwr_nue_cc_out_fv,
                       TH1D * h_leading_shwr_hits_1shwr_nue_cc_mixed,
                       TH1D * h_leading_shwr_hits_1shwr_numu_cc,
                       TH1D * h_leading_shwr_hits_1shwr_numu_cc_mixed,
                       TH1D * h_leading_shwr_hits_1shwr_nc,
                       TH1D * h_leading_shwr_hits_1shwr_nc_pi0,
                       TH1D * h_leading_shwr_hits_1shwr_cosmic,
                       TH1D * h_leading_shwr_hits_1shwr_other_mixed,
                       TH1D * h_leading_shwr_hits_1shwr_unmatched,
                       TH1D * h_leading_shwr_hits_2shwr_nue_cc,
                       TH1D * h_leading_shwr_hits_2shwr_nue_cc_out_fv,
                       TH1D * h_leading_shwr_hits_2shwr_nue_cc_mixed,
                       TH1D * h_leading_shwr_hits_2shwr_numu_cc,
                       TH1D * h_leading_shwr_hits_2shwr_numu_cc_mixed,
                       TH1D * h_leading_shwr_hits_2shwr_nc,
                       TH1D * h_leading_shwr_hits_2shwr_nc_pi0,
                       TH1D * h_leading_shwr_hits_2shwr_cosmic,
                       TH1D * h_leading_shwr_hits_2shwr_other_mixed,
                       TH1D * h_leading_shwr_hits_2shwr_unmatched);
//***************************************************************************
//***************************************************************************
void PostCutVector2DPlots(std::vector<std::tuple<int, int, double, double, double, std::string, std::string, int, int, double> > * post_cuts_v,
                          bool _post_cuts_verbose, const double intime_scale_factor, const double data_scale_factor,
                          TH2 * post_cuts_num_tracks_showers_purity_qe,
                          TH2 * post_cuts_num_tracks_showers_purity_res,
                          TH2 * post_cuts_num_tracks_showers_purity_dis,
                          TH2 * post_cuts_num_tracks_showers_purity_coh,
                          TH2 * post_cuts_num_tracks_showers_purity_mec,
                          TH2 * post_cuts_num_tracks_showers_purity_total,
                          TH2 * post_cuts_num_tracks_showers_signal_total,
                          TH2 * post_cuts_num_tracks_showers_bkg_total,
                          TH2 * post_cuts_num_tracks_showers_total_total);
//***************************************************************************
//***************************************************************************
void LeadingThetaPhi(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                     std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                     std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                     TH2D * h_ele_theta_phi_nue_cc,
                     TH2D * h_ele_theta_phi_nue_cc_out_fv,
                     TH2D * h_ele_theta_phi_nue_cc_mixed,
                     TH2D * h_ele_theta_phi_numu_cc,
                     TH2D * h_ele_theta_phi_numu_cc_mixed,
                     TH2D * h_ele_theta_phi_nc,
                     TH2D * h_ele_theta_phi_nc_pi0,
                     TH2D * h_ele_theta_phi_cosmic,
                     TH2D * h_ele_theta_phi_other_mixed,
                     TH2D * h_ele_theta_phi_unmatched);
//***************************************************************************
//***************************************************************************
void LeadingThetaPhiInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                           std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                           TH2D * h_ele_theta_phi_intime);
//***************************************************************************
//***************************************************************************
void XYZPosition(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                 std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                 std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                 const double mc_nu_vtx_x, const double mc_nu_vtx_y, const double mc_nu_vtx_z,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nue_cc,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nue_cc_out_fv,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nue_cc_mixed,
                 std::vector<TH1 *> * h_ele_pfp_xyz_numu_cc,
                 std::vector<TH1 *> * h_ele_pfp_xyz_numu_cc_mixed,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nc,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nc_pi0,
                 std::vector<TH1 *> * h_ele_pfp_xyz_cosmic,
                 std::vector<TH1 *> * h_ele_pfp_xyz_other_mixed,
                 std::vector<TH1 *> * h_ele_pfp_xyz_unmatched);
void XYZPosition(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                 std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                 std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                 const double mc_nu_vtx_x, const double mc_nu_vtx_y, const double mc_nu_vtx_z,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nue_cc,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nue_cc_out_fv,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nue_cc_mixed,
                 std::vector<TH1 *> * h_ele_pfp_xyz_numu_cc,
                 std::vector<TH1 *> * h_ele_pfp_xyz_numu_cc_mixed,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nc,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nc_pi0,
                 std::vector<TH1 *> * h_ele_pfp_xyz_cosmic,
                 std::vector<TH1 *> * h_ele_pfp_xyz_other_mixed,
                 std::vector<TH1 *> * h_ele_pfp_xyz_unmatched,
                 TH2 * h_pfp_zy_vtx_nue_cc,
                 TH2 * h_pfp_zy_vtx_all);
//***************************************************************************
//***************************************************************************
void XYZPosition(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                 std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                 std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                 const double mc_nu_vtx_x, const double mc_nu_vtx_y, const double mc_nu_vtx_z,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nue_cc,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nue_cc_out_fv,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nue_cc_mixed,
                 std::vector<TH1 *> * h_ele_pfp_xyz_numu_cc,
                 std::vector<TH1 *> * h_ele_pfp_xyz_numu_cc_mixed,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nc,
                 std::vector<TH1 *> * h_ele_pfp_xyz_nc_pi0,
                 std::vector<TH1 *> * h_ele_pfp_xyz_cosmic,
                 std::vector<TH1 *> * h_ele_pfp_xyz_other_mixed,
                 std::vector<TH1 *> * h_ele_pfp_xyz_unmatched,
                 TH2 * h_mc_vtx_xy_nue_cc,
                 TH2 * h_mc_vtx_xz_nue_cc,
                 TH2 * h_mc_vtx_yz_nue_cc,
                 TH2 * h_reco_vtx_xy_nue_cc,
                 TH2 * h_reco_vtx_xz_nue_cc,
                 TH2 * h_reco_vtx_yz_nue_cc,
                 TH2 * h_mc_vtx_xy_nue_cc_out_fv,
                 TH2 * h_mc_vtx_xz_nue_cc_out_fv,
                 TH2 * h_mc_vtx_yz_nue_cc_out_fv,
                 TH2 * h_reco_vtx_xy_nue_cc_out_fv,
                 TH2 * h_reco_vtx_xz_nue_cc_out_fv,
                 TH2 * h_reco_vtx_yz_nue_cc_out_fv,
                 TH2 * h_mc_reco_vtx_x_nue_cc,
                 TH2 * h_mc_reco_vtx_y_nue_cc,
                 TH2 * h_mc_reco_vtx_z_nue_cc,
                 TH2 * h_mc_reco_vtx_x_nue_cc_out_fv,
                 TH2 * h_mc_reco_vtx_y_nue_cc_out_fv,
                 TH2 * h_mc_reco_vtx_z_nue_cc_out_fv);
void XYZPositionInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                       std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                       std::vector<TH1 *> * h_ele_pfp_xyz_intime,
                       TH2 * h_pfp_zy_vtx_ext);
void XYZPositionInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                       std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                       std::vector<TH1 *> * h_ele_pfp_xyz_intime);
//***************************************************************************
//***************************************************************************
void EnergyCosTheta(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                    std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                    std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                    TH2 * h_ele_eng_costheta_nue_cc,
                    TH2 * h_ele_eng_costheta_nue_cc_out_fv,
                    TH2 * h_ele_eng_costheta_nue_cc_mixed,
                    TH2 * h_ele_eng_costheta_numu_cc,
                    TH2 * h_ele_eng_costheta_numu_cc_mixed,
                    TH2 * h_ele_eng_costheta_nc,
                    TH2 * h_ele_eng_costheta_nc_pi0,
                    TH2 * h_ele_eng_costheta_cosmic,
                    TH2 * h_ele_eng_costheta_other_mixed,
                    TH2 * h_ele_eng_costheta_unmatched);
void EnergyCosThetaInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                          std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                          TH2 * h_ele_eng_costheta_intime);
//***************************************************************************
//***************************************************************************
void TrueRecoEle(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                 std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                 std::vector<std::pair<std::string, int> > * tpco_classifier_v, double mc_ele_momentum, double mc_ele_cos_theta,
                 TH2D * h_true_reco_ele_momentum, TH2D * h_true_reco_ele_costheta, TH1D * h_true_num_e);
//***************************************************************************
//***************************************************************************
void EnergyCosThetaSlices(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                          std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                          const double theta_translation, const double phi_translation,
                          std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                          TH1 * h_ele_eng_for_nue_cc,
                          TH1 * h_ele_eng_for_nue_cc_out_fv,
                          TH1 * h_ele_eng_for_nue_cc_mixed,
                          TH1 * h_ele_eng_for_numu_cc,
                          TH1 * h_ele_eng_for_numu_cc_mixed,
                          TH1 * h_ele_eng_for_nc,
                          TH1 * h_ele_eng_for_nc_pi0,
                          TH1 * h_ele_eng_for_cosmic,
                          TH1 * h_ele_eng_for_other_mixed,
                          TH1 * h_ele_eng_for_unmatched,
                          TH1 * h_ele_eng_mid_nue_cc,
                          TH1 * h_ele_eng_mid_nue_cc_out_fv,
                          TH1 * h_ele_eng_mid_nue_cc_mixed,
                          TH1 * h_ele_eng_mid_numu_cc,
                          TH1 * h_ele_eng_mid_numu_cc_mixed,
                          TH1 * h_ele_eng_mid_nc,
                          TH1 * h_ele_eng_mid_nc_pi0,
                          TH1 * h_ele_eng_mid_cosmic,
                          TH1 * h_ele_eng_mid_other_mixed,
                          TH1 * h_ele_eng_mid_unmatched,
                          TH1 * h_ele_eng_back_nue_cc,
                          TH1 * h_ele_eng_back_nue_cc_out_fv,
                          TH1 * h_ele_eng_back_nue_cc_mixed,
                          TH1 * h_ele_eng_back_numu_cc,
                          TH1 * h_ele_eng_back_numu_cc_mixed,
                          TH1 * h_ele_eng_back_nc,
                          TH1 * h_ele_eng_back_nc_pi0,
                          TH1 * h_ele_eng_back_cosmic,
                          TH1 * h_ele_eng_back_other_mixed,
                          TH1 * h_ele_eng_back_unmatched);
void EnergyCosThetaSlicesInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                const double theta_translation, const double phi_translation,
                                TH1 * h_ele_eng_for_intime,
                                TH1 * h_ele_eng_mid_intime,
                                TH1 * h_ele_eng_back_intime);
//***************************************************************************
//***************************************************************************
void DifferentialEnergySlices(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                              std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                              std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                              TH1 * h_low_true_momentum, TH1 * h_med_true_momentum, TH1 * h_high_true_momentum);
//***************************************************************************
//***************************************************************************
void IsContainedPlot(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                     std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                     std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                     std::vector<double> fv_boundary_v,
                     TH1 * h_track_containment_nue_cc,
                     TH1 * h_track_containment_nue_cc_out_fv,
                     TH1 * h_track_containment_nue_cc_mixed,
                     TH1 * h_track_containment_numu_cc,
                     TH1 * h_track_containment_numu_cc_mixed,
                     TH1 * h_track_containment_nc,
                     TH1 * h_track_containment_nc_pi0,
                     TH1 * h_track_containment_cosmic,
                     TH1 * h_track_containment_other_mixed,
                     TH1 * h_track_containment_unmatched);
void IsContainedPlotInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                           std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                           std::vector<double> fv_boundary_v, TH1 * h_track_containment_intime);
//***************************************************************************
//***************************************************************************
void dEdxCollectionAngle(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                         std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                         std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                         TH2D * h_dedx_collection_angle_nue_cc,
                         TH2D * h_dedx_collection_angle_nue_cc_mixed,
                         TH2D * h_dedx_collection_angle_nue_cc_out_fv,
                         TH2D * h_dedx_collection_angle_numu_cc,
                         TH2D * h_dedx_collection_angle_nc,
                         TH2D * h_dedx_collection_angle_cosmic,
                         TH2D * h_dedx_collection_angle_nc_pi0,
                         TH2D * h_dedx_collection_angle_numu_cc_mixed,
                         TH2D * h_dedx_collection_angle_other_mixed,
                         TH2D * h_dedx_collection_angle_unmatched     );
void dEdxCollectionAngleInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                               std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                               TH2D * h_dedx_collection_angle_intime);
//***************************************************************************
//***************************************************************************
void PostCutsVtxFlashDownstream(std::vector< double > largest_flash_v, std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                                TH1D * h_vtx_flash_nue_cc, TH1D * h_vtx_flash_nue_cc_out_fv, TH1D * h_vtx_flash_nue_cc_mixed,
                                TH1D * h_vtx_flash_numu_cc, TH1D * h_vtx_flash_nc,
                                TH1D * h_vtx_flash_cosmic, TH1D * h_vtx_flash_nc_pi0,
                                TH1D * h_vtx_flash_numu_cc_mixed, TH1D * h_vtx_flash_other_mixed,
                                TH1D * h_vtx_flash_unmatched);
//***************************************************************************
//***************************************************************************
void PostCutsVtxFlashUpstream(std::vector< double > largest_flash_v, std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                              std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                              std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                              TH1D * h_vtx_flash_nue_cc, TH1D * h_vtx_flash_nue_cc_out_fv, TH1D * h_vtx_flash_nue_cc_mixed,
                              TH1D * h_vtx_flash_numu_cc, TH1D * h_vtx_flash_nc,
                              TH1D * h_vtx_flash_cosmic, TH1D * h_vtx_flash_nc_pi0,
                              TH1D * h_vtx_flash_numu_cc_mixed, TH1D * h_vtx_flash_other_mixed,
                              TH1D * h_vtx_flash_unmatched);
//***************************************************************************
//***************************************************************************
void PostCutsVtxFlashDownstreamInTime(std::vector< double > largest_flash_v, std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                      std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose, TH1D * h_vtx_flash_intime);
//***************************************************************************
//***************************************************************************
void PostCutsVtxFlashUpstreamInTime(std::vector< double > largest_flash_v, std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                    std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose, TH1D * h_vtx_flash_intime);
//***************************************************************************
//***************************************************************************
void FillTrueRecoEnergy(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                        std::vector<std::pair<int, std::string> > * passed_tpco,
                        std::vector<std::pair<std::string, int> > * tpco_classifier_v, double mc_ele_energy,
                        TH1D * h_mc_ele_energy,
                        TH1D * h_reco_ele_energy,
                        TH2D * h_mc_reco_ele_energy);
//***************************************************************************
//***************************************************************************
void PostCutsLeadingMomentumTrueParticle(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                         std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                         std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                                         TH1D * h_leading_momentum_electron,
                                         TH1D * h_leading_momentum_photon,
                                         TH1D * h_leading_momentum_proton,
                                         TH1D * h_leading_momentum_pion,
                                         TH1D * h_leading_momentum_muon,
                                         TH1D * h_leading_momentum_kaon,
                                         TH1D * h_leading_momentum_neutron,
                                         TH1D * h_leading_momentum_mc_unmatched);
void PostCutsLeadingMomentumTrueParticleInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                               std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                               TH1D * h_leading_momentum_type_cosmic);
//***************************************************************************
//***************************************************************************
void PostCutsLeadingMomentum(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                             std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                             std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                             TH1D * h_ele_momentum_nue_cc,
                             TH1D * h_ele_momentum_nue_cc_out_fv,
                             TH1D * h_ele_momentum_nue_cc_mixed,
                             TH1D * h_ele_momentum_numu_cc,
                             TH1D * h_ele_momentum_numu_cc_mixed,
                             TH1D * h_ele_momentum_nc,
                             TH1D * h_ele_momentum_nc_pi0,
                             TH1D * h_ele_momentum_cosmic,
                             TH1D * h_ele_momentum_other_mixed,
                             TH1D * h_ele_momentum_unmatched);
//***************************************************************************
//***************************************************************************
void PostCutsLeadingMomentumInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                   std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                   TH1D * h_ele_momentum_intime);
//***************************************************************************
//***************************************************************************
void LeadingMomentumTrackTopology(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                  std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                  std::vector<std::pair<std::string, int> > * tpco_classifier_v,
                                  TH1D * h_ele_pfp_momentum_no_track_nue_cc,
                                  TH1D * h_ele_pfp_momentum_no_track_nue_cc_out_fv,
                                  TH1D * h_ele_pfp_momentum_no_track_nue_cc_mixed,
                                  TH1D * h_ele_pfp_momentum_no_track_numu_cc,
                                  TH1D * h_ele_pfp_momentum_no_track_numu_cc_mixed,
                                  TH1D * h_ele_pfp_momentum_no_track_nc,
                                  TH1D * h_ele_pfp_momentum_no_track_nc_pi0,
                                  TH1D * h_ele_pfp_momentum_no_track_cosmic,
                                  TH1D * h_ele_pfp_momentum_no_track_other_mixed,
                                  TH1D * h_ele_pfp_momentum_no_track_unmatched,
                                  TH1D * h_ele_pfp_momentum_has_track_nue_cc,
                                  TH1D * h_ele_pfp_momentum_has_track_nue_cc_out_fv,
                                  TH1D * h_ele_pfp_momentum_has_track_nue_cc_mixed,
                                  TH1D * h_ele_pfp_momentum_has_track_numu_cc,
                                  TH1D * h_ele_pfp_momentum_has_track_numu_cc_mixed,
                                  TH1D * h_ele_pfp_momentum_has_track_nc,
                                  TH1D * h_ele_pfp_momentum_has_track_nc_pi0,
                                  TH1D * h_ele_pfp_momentum_has_track_cosmic,
                                  TH1D * h_ele_pfp_momentum_has_track_other_mixed,
                                  TH1D * h_ele_pfp_momentum_has_track_unmatched);
//***************************************************************************
//***************************************************************************
void LeadingMomentumTrackTopologyInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                                        std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                                        TH1D * h_ele_pfp_momentum_no_track_intime,
                                        TH1D * h_ele_pfp_momentum_has_track_intime);
//***************************************************************************
//***************************************************************************
void dEdxTheta(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
               std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
               std::vector<std::pair<std::string, int> > * tpco_classifier_v,
               TH2D * h_dedx_theta_nue_cc,
               TH2D * h_dedx_theta_nue_cc_mixed,
               TH2D * h_dedx_theta_nue_cc_out_fv,
               TH2D * h_dedx_theta_numu_cc,
               TH2D * h_dedx_theta_nc,
               TH2D * h_dedx_theta_cosmic,
               TH2D * h_dedx_theta_nc_pi0,
               TH2D * h_dedx_theta_numu_cc_mixed,
               TH2D * h_dedx_theta_other_mixed,
               TH2D * h_dedx_theta_unmatched);
//***************************************************************************
//***************************************************************************
void dEdxThetaInTime(std::vector<xsecAna::TPCObjectContainer> * tpc_object_container_v,
                     std::vector<std::pair<int, std::string> > * passed_tpco, bool _verbose,
                     TH2D * h_dedx_theta_intime);
//***************************************************************************
//***************************************************************************
};
#endif
