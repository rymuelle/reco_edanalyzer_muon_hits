import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

# initialize MessageLogger and output report
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.categories.append('Demo')
process.MessageLogger.cerr.INFO = cms.untracked.PSet(
    limit = cms.untracked.int32(-1)
)
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        #'file:/eos/cms/store/group/alca_muonalign/ryan/singleMuonGun_10_1_0_pre3_ideal_10k_residual_test/crab_singleMuonGun_10_1_0_pre3_ideal_10k_residual_test/180322_200321/0000/step1_10.root'
        'file:/eos/cms/store/group/alca_muonalign/ryan/singleMuonGun_10_1_0_pre3_realistic_10k_residual_test/crab_singleMuonGun_10_1_0_pre3_realistic_10k_residual_test/180323_153106/0000/step1_10.root'
        #'file:/afs/cern.ch/work/r/rymuelle/public/10X_Alignment/CMSSW_10_1_0_pre3/src/Producers/SingleMuonGun/test/step1.root'
    )
)

process.demo = cms.EDAnalyzer('reco_analyzer',
	#generalTracks          = cms.InputTag("generalTracks", "", "RECO")
	generalTracks          = cms.InputTag("globalMuons", "", "RECO")
)


process.p = cms.Path(process.demo)
