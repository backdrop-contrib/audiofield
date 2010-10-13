AUDIOFIELD.MODULE
--------------------------------------------------------------------------------
This module allows embedding an audio file in a CCK field
This module is for adding new field that allows embedding an mp3 audio.

In order to activate this module you have to get its audio players from the following links
1. http://wpaudioplayer.com/download *Note make sure you should download the standalone edition
2. http://sourceforge.net/projects/musicplayer/files/musicplayer/slim-player-0.2.3b/xspf_player_slim-correct-0.2.3.zip/download
3. http://www.premiumbeat.com/flash_resources/free_flash_music_player/single_track_flash_mp3_player.php

Once you got the above audio players you have to create a new folder at this 
directory "sites/all/libraries/player" and name it as "player". now you can unzip 
the audio players directly into the "player" folder.

This module gives you the ability to choose the audio player you would like to 
get on your web site from many audio players, from configuration page.

Finally you have to put any mp3 audio file at "\sites\all\libraries\player\" 
and you have to name it as Sample_Track.mp3, this step just to gives the ability
to test all audio players before you choose your default audio player 

SUPPORTED FILE FORMATS:
Originally this module supports only mp3 audio files. But other modules can extend this by implementing theme_audiofield_play_FILE-EXTENSION() 
in their modules. For example to implement support for wav files you should register audiofield_play_wav from your module hook_theme :

function YOURMODULENAME_field_theme() {
  $theme = array('audiofield_play_wav' => array(
      'arguments' => array('element' => NULL),
  ));
  return $theme;
}

and then you can render your player through:

function theme_audiofield_play_wav($element){
	$output="CODE FOR WAV PLAYER"';
	return $output;
}

MAINTAINERS
--------------------------------------------------------------------------------
Tamer Zoubi - <tamerzg@gmail.com>


