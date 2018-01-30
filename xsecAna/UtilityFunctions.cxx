#include "UtilityFunctions.h"

namespace xsecAna {

//______________________________________________________________________________

void utility::GetNumberOfHitsPerPlane(art::Event const & e,
                                      std::string _particleLabel,
                                      lar_pandora::TrackVector track_v,
                                      int & nhits_u,
                                      int & nhits_v,
                                      int & nhits_w ) {

	nhits_u = 0;
	nhits_v = 0;
	nhits_w = 0;

	lar_pandora::TrackVector trackVector;
	lar_pandora::TracksToHits tracksToHits;
	lar_pandora::LArPandoraHelper::CollectTracks( e, _particleLabel, trackVector, tracksToHits );

	// Loop over the tracks in this TPC Object
	for (unsigned int t = 0; t < track_v.size(); t++) {

		// Get the hits associated with the track
		lar_pandora::HitVector hit_v = tracksToHits.at(track_v[t]);

		// Check where the hit is coming from
		for (unsigned int h = 0; h < hit_v.size(); h++) {

			if (hit_v[h]->View() == 0) nhits_u++;
			if (hit_v[h]->View() == 1) nhits_v++;
			if (hit_v[h]->View() == 2) nhits_w++;

		}
	}

}

//______________________________________________________________________________

void utility::GetNumberOfHitsPerPlane(art::Event const & e,
                                      std::string _particleLabel,
                                      art::Ptr<recob::Track> track,
                                      int & nhits_u,
                                      int & nhits_v,
                                      int & nhits_w ) {

	nhits_u = 0;
	nhits_v = 0;
	nhits_w = 0;

	lar_pandora::TrackVector trackVector;
	lar_pandora::TracksToHits tracksToHits;
	lar_pandora::LArPandoraHelper::CollectTracks( e, _particleLabel, trackVector, tracksToHits );

	// Get the hits associated with the track
	lar_pandora::HitVector hit_v = tracksToHits.at(track);

	// Check where the hit is coming from
	for (unsigned int h = 0; h < hit_v.size(); h++) {

		if (hit_v[h]->View() == 0) nhits_u++;
		if (hit_v[h]->View() == 1) nhits_v++;
		if (hit_v[h]->View() == 2) nhits_w++;

	}
}
//______________________________________________________________________________
void utility::GetNumberOfHitsPerPlane(art::Event const & e,
                                      std::string _particleLabel,
                                      lar_pandora::ShowerVector shower_v,
                                      int & nhits_u,
                                      int & nhits_v,
                                      int & nhits_w ) {

	nhits_u = 0;
	nhits_v = 0;
	nhits_w = 0;

	lar_pandora::ShowerVector showerVector;
	lar_pandora::ShowersToHits showersToHits;
	lar_pandora::LArPandoraHelper::CollectShowers( e, _particleLabel, showerVector, showersToHits );

	// Loop over the showers in this TPC Object
	for (unsigned int t = 0; t < shower_v.size(); t++) {

		// Get the hits associated with the track
		lar_pandora::HitVector hit_v = showersToHits.at(shower_v[t]);

		// Check where the hit is coming from
		for (unsigned int h = 0; h < hit_v.size(); h++) {

			if (hit_v[h]->View() == 0) nhits_u++;
			if (hit_v[h]->View() == 1) nhits_v++;
			if (hit_v[h]->View() == 2) nhits_w++;

		}
	}
}
//______________________________________________________________________________
void utility::GetNumberOfHitsPerPlane(art::Event const & e,
                                      std::string _particleLabel,
                                      art::Ptr<recob::Shower> shower,
                                      int & nhits_u,
                                      int & nhits_v,
                                      int & nhits_w ) {

	nhits_u = 0;
	nhits_v = 0;
	nhits_w = 0;

	lar_pandora::ShowerVector showerVector;
	lar_pandora::ShowersToHits showersToHits;
	lar_pandora::LArPandoraHelper::CollectShowers( e, _particleLabel, showerVector, showersToHits );

	// Get the hits associated with the track
	lar_pandora::HitVector hit_v = showersToHits.at(shower);

	// Check where the hit is coming from
	for (unsigned int h = 0; h < hit_v.size(); h++) {

		if (hit_v[h]->View() == 0) nhits_u++;
		if (hit_v[h]->View() == 1) nhits_v++;
		if (hit_v[h]->View() == 2) nhits_w++;

	}

}
//______________________________________________________________________________
void utility::GetEnergyPerPlane(art::Event const & e,
                                std::string _particleLabel,
                                art::Ptr<recob::Shower> shower,
                                double & calibration_u,
                                double & calibration_v,
                                double & calibration_w,
                                double & energy_u,
                                double & energy_v,
                                double & energy_w ) {
	energy_u = 0;
	energy_v = 0;
	energy_w = 0;

	lar_pandora::ShowerVector showerVector;
	lar_pandora::ShowersToHits showersToHits;
	//construct a shower to hit map
	lar_pandora::LArPandoraHelper::CollectShowers( e, _particleLabel, showerVector, showersToHits );

	// Get the hits associated with the shower
	lar_pandora::HitVector hit_v = showersToHits.at(shower);

	double integral_u = 0;
	double integral_v = 0;
	double integral_w = 0;

	// Check where the hit is coming from
	for (auto const hit : hit_v)
	{
		if (hit->View() == 0) {integral_u += hit->Integral(); }
		if (hit->View() == 1) {integral_v += hit->Integral(); }
		if (hit->View() == 2) {integral_w += hit->Integral(); }
	}
	energy_u = integral_u * calibration_u;
	energy_v = integral_v * calibration_v;
	energy_w = integral_w * calibration_w;
}
//______________________________________________________________________________
void utility::GetEnergyPerPlane(art::Event const & e,
                                std::string _particleLabel,
                                art::Ptr<recob::Track> track,
                                double & calibration_u,
                                double & calibration_v,
                                double & calibration_w,
                                double & energy_u,
                                double & energy_v,
                                double & energy_w ) {
	energy_u = 0;
	energy_v = 0;
	energy_w = 0;

	lar_pandora::TrackVector trackVector;
	lar_pandora::TrackssToHits tracksToHits;
	//construct a track to hit map
	lar_pandora::LArPandoraHelper::CollectTracks( e, _particleLabel, trackVector, tracksToHits );

	// Get the hits associated with the track
	lar_pandora::HitVector hit_v = tracksToHits.at(track);

	double integral_u = 0;
	double integral_v = 0;
	double integral_w = 0;

	// Check where the hit is coming from
	for (unsigned int h = 0; h < hit_v.size(); h++)
	{
		if (hit->View() == 0) {integral_u += hit->Integral(); }
		if (hit->View() == 1) {integral_v += hit->Integral(); }
		if (hit->View() == 2) {integral_w += hit->Integral(); }
	}
	energy_u = integral_u * calibration_u;
	energy_v = integral_v * calibration_v;
	energy_w = integral_w * calibration_w;
}
//___________________________________________________________________________________________________
void utility::GetTrackPurityAndEfficiency( lar_pandora::HitVector recoHits, double & trackPurity, double & trackEfficiency ) {

	art::ServiceHandle<cheat::BackTracker> bt;

	// map from geant track id to true track deposited energy
	std::map<int,double> trkidToIDE;

	for(size_t h = 0; h < recoHits.size(); h++) {

		art::Ptr<recob::Hit> recoHit = recoHits[h];
		std::vector<sim::TrackIDE> eveIDs = bt->HitToEveID(recoHit);

		for(size_t e = 0; e < eveIDs.size(); ++e) {
			//std::cout<<"[Hit "<< h<<"] hit plane: "<<recoHit->View()<<" "<<e<<" "<<eveIDs[e].trackID<<" "<<eveIDs[e].energy<<" "
			//<<eveIDs[e].energyFrac<<"   pdg "<< (bt->TrackIDToParticle(eveIDs[e].trackID))->PdgCode()<<"   process "
			//<<(bt->TrackIDToParticle(eveIDs[e].trackID))->Process()<<std::endl;
			trkidToIDE[eveIDs[e].trackID] += eveIDs[e].energy;
		}
	}

	double maxe = -1;
	double tote = 0;
	int trackid;
	for(auto const& ii : trkidToIDE) {
		tote += ii.second;
		if ((ii.second)>maxe) {
			maxe = ii.second;
			trackid = ii.first;
		}
	}

	if (tote>0) {
		trackPurity = maxe/tote;
	}

	std::vector<sim::IDE> vide(bt->TrackIDToSimIDE(trackid));
	double totalEnergyFromMainTrack = 0;
	for (const sim::IDE& ide: vide) {
		totalEnergyFromMainTrack += ide.energy;
	}

	trackEfficiency = maxe/(totalEnergyFromMainTrack); //totalEnergyFromMainTrack includes both inductions and collection energies

	return;
}

void utility::ConstructShowerdQdX(xsecAna::GeometryHelper geoHelper, bool is_data, std::map <art::Ptr<recob::Cluster>, std::vector<art::Ptr< recob::Hit> > > ClusterToHitsMap,
                                  std::vector<art::Ptr<recob::Cluster> > clusters, double _dQdxRectangleLength, double _dQdxRectangleWidth,
                                  const art::Ptr<recob::Shower> shower, std::vector< std::vector < double > > & shower_cluster_dqdx, bool _verbose)
{
	double _gain = 0;
	const double _data_gain = 240;
	const double _mc_gain = 200;

	if(is_data) {_gain = _data_gain; }
	if(!is_data) {_gain = _mc_gain; }

	detinfo::DetectorProperties const * detprop = lar::providerFrom<detinfo::DetectorPropertiesService>();
	const double drift = detprop->DriftVelocity() * 1e-3;


	TVector3 shower_dir(shower->Direction().X(), shower->Direction().Y(),
	                    shower->Direction().Z());

	// TODO Use variable from detector properties!
	// To get the time in ns -> 4.8 ms / 9600 ticks * 1e6 = 500
	// 0.3 wire spacing

	const double fromTickToNs = 4.8 / detprop->ReadOutWindowSize() * 1e6;
	const double wire_spacing = 0.3;

	const int n_clusters = clusters.size();
	//shower_cluster_dqdx.resize(n_clusters);

	if(_verbose) {std::cout << "[dQdx] Clusters size: " << n_clusters << std::endl; }
	int cluster_num = 0;
	//these are the clusters associated with a given shower
	for(auto const cluster : clusters)
	{
		std::cout << "Cluster Num: " << cluster_num << std::endl;
		auto const find_iter = ClusterToHitsMap.find(cluster);
		if (find_iter == ClusterToHitsMap.end()) {continue; }
		std::vector<art::Ptr<recob::Hit> > hits_v = find_iter->second;

		const int cluster_start_wire = cluster->StartWire();
		const int cluster_end_wire = cluster->EndWire();
		const double cluster_start_position = cluster_start_wire * wire_spacing;
		const double cluster_start_ns = drift * cluster->StartTick() * fromTickToNs;
		std::vector< double > cluster_start = {cluster_start_position, cluster_start_ns};
		const double cluster_end_position = cluster_end_wire * wire_spacing;
		const double cluster_end_ns = drift * cluster->EndTick() * fromTickToNs;

		const double cluster_length = sqrt(pow((cluster_end_position - cluster_start_position),2) +
		                                   pow((cluster_end_ns - cluster_start_ns),2));
		if(cluster_length <= 0) {std::cout << " [dQdx] Cluster Length is Less than 0!" << std::endl; continue; }
		std::vector<double> cluster_axis = {cos(cluster->StartAngle()), sin(cluster->StartAngle())};

		// Build rectangle 4 x 1 cm around the cluster axis
		std::vector<std::vector<double> > rectangle_points;
		geoHelper.buildRectangle(_dQdxRectangleLength, _dQdxRectangleWidth,
		                         cluster_start, cluster_axis, rectangle_points);

		bool first_point = true;
		shower_cluster_dqdx.at(cluster_num).resize(3);//the number of planes
		std::vector<double> dqdx_plane0;
		std::vector<double> dqdx_plane1;
		std::vector<double> dqdx_plane2;
		for(auto const hit : hits_v)
		{
			const double hit_position = hit->WireID().Wire * wire_spacing;
			const double hit_ns       = hit->PeakTime() * drift * fromTickToNs;
			std::vector < double >  hit_pos = {hit_position, hit_ns};
			double wire_pitch = geoHelper.getPitch(shower_dir, cluster->Plane().Plane);
			//check if the hits associated with the cluster are inside the box we define - standard is 4 x 1 cm
			bool is_inside = geoHelper.isInside(hit_pos, rectangle_points);

			// The function considers points on the border outside, manually add the first point
			if(first_point || is_inside)
			{
				const double charge = hit->Integral() * _gain;
				if(cluster->Plane().Plane == 0) {dqdx_plane0.push_back(charge / wire_pitch); }
				if(cluster->Plane().Plane == 1) {dqdx_plane1.push_back(charge / wire_pitch); }
				if(cluster->Plane().Plane == 2) {dqdx_plane2.push_back(charge / wire_pitch); }
			}
			if(first_point == true) {first_point = false; }
		}//end looping hits

		//Now I want to see the total integrated charge for this plane
		const double total_dqdx_plane0 = std::accumulate(dqdx_plane0.begin(), dqdx_plane0.end(), 0.0) / _dQdxRectangleLength;
		const double total_dqdx_plane1 = std::accumulate(dqdx_plane1.begin(), dqdx_plane1.end(), 0.0) / _dQdxRectangleLength;
		const double total_dqdx_plane2 = std::accumulate(dqdx_plane2.begin(), dqdx_plane2.end(), 0.0) / _dQdxRectangleLength;

		shower_cluster_dqdx.at(cluster_num).at(0) = total_dqdx_plane0;
		shower_cluster_dqdx.at(cluster_num).at(1) = total_dqdx_plane1;
		shower_cluster_dqdx.at(cluster_num).at(2) = total_dqdx_plane2;

		// Get the median
		size_t n_0 = dqdx_plane0.size() / 2;
		size_t n_1 = dqdx_plane1.size() / 2;
		size_t n_2 = dqdx_plane2.size() / 2;
		if (n_0 > 0)
		{
			std::nth_element(dqdx_plane0.begin(), dqdx_plane0.begin() + n_0, dqdx_plane0.end());
			shower_cluster_dqdx.at(cluster_num).at(0) = dqdx_plane0.at(n_0);
		}
		if (n_1 > 0)
		{
			std::nth_element(dqdx_plane1.begin(), dqdx_plane1.begin() + n_1, dqdx_plane1.end());
			shower_cluster_dqdx.at(cluster_num).at(1) = dqdx_plane1.at(n_1);
		}
		if (n_2 > 0)
		{
			std::nth_element(dqdx_plane2.begin(), dqdx_plane2.begin() + n_2, dqdx_plane2.end());
			shower_cluster_dqdx.at(cluster_num).at(2) = dqdx_plane2.at(n_2);
		}

		cluster_num++;
	}//end looping clusters
	std::cout << "[dQdx] Finished Calculating dQdx" << std::endl;
}//end function dqdx

void utility::ConvertdEdX(std::vector< std::vector < double > > & shower_cluster_dqdx, std::vector<double> & shower_dEdx)
{
	const double work_function = 23;//eV
	const double recombination_factor = 0.62;

	//sum all of the charge from the clusters for the shower per plane
	for(const std::vector<double> cluster_dqdx : shower_cluster_dqdx)
	{
		shower_dEdx.at(0) += cluster_dqdx.at(0) * (work_function / 1e6) / recombination_factor;
		shower_dEdx.at(1) += cluster_dqdx.at(1) * (work_function / 1e6) / recombination_factor;
		shower_dEdx.at(2) += cluster_dqdx.at(2) * (work_function / 1e6) / recombination_factor;
	}//saves dEdx in MeV/cm
}//end function dEdx

}//end namespace
