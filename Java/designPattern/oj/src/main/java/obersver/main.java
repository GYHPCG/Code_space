package obersver;

public class main {

    public static void main(String[] args) {

        GameScore gameScore = new GameScore();

        ScoreDB scoreDB = new ScoreDB();

        VoiceScore voiceScore = new VoiceScore();

        DisplayScore displayScore = new DisplayScore();

        gameScore.registerObserver(scoreDB);

        gameScore.registerObserver(voiceScore);

        gameScore.registerObserver(displayScore);

        gameScore.setScore("Game10minute", 1, 0);

        gameScore.removeObserver(voiceScore);

        gameScore.setScore("Game19minute", 1, 1);

    }


}