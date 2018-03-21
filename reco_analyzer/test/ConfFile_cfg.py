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

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'file:/afs/cern.ch/work/r/rymuelle/public/10X_Alignment/CMSSW_9_4_4/src/Producers/SingleMuonGun/test/singleMuonGun_ReducedRECO_mcRun_2016.root'
    )
)

process.demo = cms.EDAnalyzer('reco_analyzer',
	generalTracks          = cms.InputTag("generalTracks", "", "RECO")
)


process.p = cms.Path(process.demo)
