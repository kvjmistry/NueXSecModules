#include "TpcObjectContainer.h"

namespace xsecAna {

// TPCObjectContainer::TPCObjectContainer() {
// }

//

void TPCObjectContainer::AddParticle ( ParticleContainer _particle){
	fParticleList.push_back(_particle);
}

ParticleContainer TPCObjectContainer::GetParticle(int _i) const {
	return fParticleList.at(_i);
}

//
void TPCObjectContainer::SetIsData    (int _is_data){
	is_data = _is_data;
}
void TPCObjectContainer::SetRunNumber (int run_number){
	run = run_number;
}
void TPCObjectContainer::SetSubRunNumber (int subrun_number){
	subrun = subrun_number;
}
void TPCObjectContainer::SetEventNumber(int event_number){
	event = event_number;
}
void TPCObjectContainer::SetIndex (int _index){
	index = _index;
}
void TPCObjectContainer::SetNumPFParticles (int _n_pfp){
	n_pfp = _n_pfp;
}
void TPCObjectContainer::SetNumPFPNeutrinos (int _n_pfp_nu){
	n_pfp_nu = _n_pfp_nu;
}
void TPCObjectContainer::SetMode (int _mode){
	mode = _mode;
}
void TPCObjectContainer::SetOrigin (std::string _origin){
	origin = _origin;
}
void TPCObjectContainer::SetCCNC (int _is_cc){
	is_cc = _is_cc;
}
void TPCObjectContainer::SetHasMCPi0 ( int _has_mc_pi0){
	has_mc_pi0 = _has_mc_pi0;
}

void TPCObjectContainer::SetNPfpTracks  (int _n_pfp_tracks){
	n_pfp_tracks = _n_pfp_tracks;
}
void TPCObjectContainer::SetNPfpShowers (int _n_pfp_showers){
	n_pfp_showers = _n_pfp_showers;
}
//void TPCObjectContainer::SetLeadingParticle( ParticleContainer _leading_particle){
//	leading_particle = _leading_particle;
//}

//the tpc object pdg codes correspond to the in-coming neutrino object
void TPCObjectContainer::SetmcPdgCode( int _mc_pdg_code){
	mc_pdg_code = _mc_pdg_code;
}
void TPCObjectContainer::SetpfpPdgCode( int _pfp_pdg_code){
	pfp_pdg_code = _pfp_pdg_code;
}


//the tpc object takes the neutrino vertex
void TPCObjectContainer::SetmcVtxX  (double _mc_vtx_x){
	mc_vtx_x = _mc_vtx_x;
}
void TPCObjectContainer::SetmcVtxY  (double _mc_vtx_y){
	mc_vtx_y = _mc_vtx_y;
}
void TPCObjectContainer::SetmcVtxZ  (double _mc_vtx_z){
	mc_vtx_z = _mc_vtx_z;
}
void TPCObjectContainer::SetpfpVtxX (double _pfp_vtx_x){
	pfp_vtx_x = _pfp_vtx_x;
}
void TPCObjectContainer::SetpfpVtxY (double _pfp_vtx_y){
	pfp_vtx_y = _pfp_vtx_y;
}
void TPCObjectContainer::SetpfpVtxZ (double _pfp_vtx_z){
	pfp_vtx_z = _pfp_vtx_z;
}

void TPCObjectContainer::SetCompleteness (double _completeness){
	completeness = _completeness;
}
void TPCObjectContainer::SetPurity (double _purity){
	purity = _purity;
}

void TPCObjectContainer::SetNumMCHits   (int _n_mc_hits){
	n_mc_hits = _n_mc_hits;
}
void TPCObjectContainer::SetNumMCHitsU  (int _n_mc_hits_u){
	n_mc_hits_u = _n_mc_hits_u;
}
void TPCObjectContainer::SetNumMCHitsV  (int _n_mc_hits_v){
	n_mc_hits_v = _n_mc_hits_v;
}
void TPCObjectContainer::SetNumMCHitsW  (int _n_mc_hits_w){
	n_mc_hits_w = _n_mc_hits_w;
}
void TPCObjectContainer::SetNumPFPHits  (int _n_pfp_hits){
	n_pfp_hits = _n_pfp_hits;
}
void TPCObjectContainer::SetNumPFPHitsU (int _n_pfp_hits_u){
	n_pfp_hits_u = _n_pfp_hits_u;
}
void TPCObjectContainer::SetNumPFPHitsV (int _n_pfp_hits_v){
	n_pfp_hits_v = _n_pfp_hits_v;
}
void TPCObjectContainer::SetNumPFPHitsW (int _n_pfp_hits_w){
	n_pfp_hits_w = _n_pfp_hits_w;
}

void TPCObjectContainer::SetNumMatchedHits  (int _n_matched_hits){
	n_matched_hits = _n_matched_hits;
}
void TPCObjectContainer::SetNumMatchedHitsU (int _n_matched_hits_u){
	n_matched_hits_u = _n_matched_hits_u;
}
void TPCObjectContainer::SetNumMatchedHitsV (int _n_matched_hits_v){
	n_matched_hits_v = _n_matched_hits_v;
}
void TPCObjectContainer::SetNumMatchedHitsW (int _n_matched_hits_w){
	n_matched_hits_w = _n_matched_hits_w;
}

//----------------
//Getter Functions
//----------------

int TPCObjectContainer::IsData    () const {
	return is_data;
}
int TPCObjectContainer::RunNumber () const {
	return run;
}
int TPCObjectContainer::SubRunNumber () const {
	return subrun;
}
int TPCObjectContainer::EventNumber() const {
	return event;
}
int TPCObjectContainer::Index () const {
	return index;
}

int TPCObjectContainer::NumPFParticles () const {
	return n_pfp;
}
int TPCObjectContainer::NumPFPNeutrinos () const {
	return n_pfp_nu;
}
int TPCObjectContainer::NPfpTracks  () const {
	return n_pfp_tracks;
}
int TPCObjectContainer::NPfpShowers () const {
	return n_pfp_showers;
}
/*ParticleContainer TPCObjectContainer::LeadingParticle () const {
        return leading_particle;
   }*/

int TPCObjectContainer::Mode () const {
	return mode;
}
std::string TPCObjectContainer::Origin () const {
	return origin;
}
int TPCObjectContainer::CCNC () const {
	return is_cc;
}
int TPCObjectContainer::HasMCPi0 () const {
	return has_mc_pi0;
}

int TPCObjectContainer::MCParticlePdgCode() const {
	return mc_pdg_code;
}
int TPCObjectContainer::PFParticlePdgCode() const {
	return pfp_pdg_code;
}


double TPCObjectContainer::mcVtxX  () const {
	return mc_vtx_x;
}
double TPCObjectContainer::mcVtxY  () const {
	return mc_vtx_y;
}
double TPCObjectContainer::mcVtxZ  () const {
	return mc_vtx_z;
}
double TPCObjectContainer::pfpVtxX () const {
	return pfp_vtx_x;
}
double TPCObjectContainer::pfpVtxY () const {
	return pfp_vtx_y;
}
double TPCObjectContainer::pfpVtxZ () const {
	return pfp_vtx_z;
}

double TPCObjectContainer::Completeness () const {
	return completeness;
}
double TPCObjectContainer::Purity () const {
	return purity;
}

int TPCObjectContainer::NumMCHits   () const {
	return n_mc_hits;
}
int TPCObjectContainer::NumMCHitsU  () const {
	return n_mc_hits_u;
}
int TPCObjectContainer::NumMCHitsV  () const {
	return n_mc_hits_v;
}
int TPCObjectContainer::NumMCHitsW  () const {
	return n_mc_hits_w;
}
int TPCObjectContainer::NumPFPHits  () const {
	return n_pfp_hits;
}
int TPCObjectContainer::NumPFPHitsU () const {
	return n_pfp_hits_u;
}
int TPCObjectContainer::NumPFPHitsV () const {
	return n_pfp_hits_v;
}
int TPCObjectContainer::NumPFPHitsW () const {
	return n_pfp_hits_w;
}

int TPCObjectContainer::NumMatchedHits  () const {
	return n_matched_hits;
}
int TPCObjectContainer::NumMatchedHitsU () const {
	return n_matched_hits_u;
}
int TPCObjectContainer::NumMatchedHitsV () const {
	return n_matched_hits_v;
}
int TPCObjectContainer::NumMatchedHitsW () const {
	return n_matched_hits_w;
}



}//end namespace
