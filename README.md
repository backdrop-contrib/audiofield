AudioField
======================

This module adds a new field that allows embedding mp3 audio. It adds the
ability to upload and play audio files in an HTML5 audio player or one of a few
Flash players.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

- (optional) Visit the configuration page under Administration > Configuration >
  Media > AudioField (admin/config/media/audiofield) to set the audio player
  directory.

- (optional) Add audio players. This module will use the Google Reader MP3
  Player by default, but there are several other supported players:
  1. http://wpaudioplayer.com/download Download the standalone edition.
  2. http://prdownloads.sourceforge.net/musicplayer/xspf_player_slim-correct-0.2.3.zip?download
  3. http://prdownloads.sourceforge.net/musicplayer/button_player-0.1.zip?download
  4. http://www.premiumbeat.com/flash_music_players/original/single (DEPRECATED)
  5. http://www.premiumbeat.com/flash_music_players/original/thin   (DEPRECATED)
  6. http://www.premiumbeat.com/flash_music_players/original/mini   (DEPRECATED)
  7. http://www.schillmania.com/projects/soundmanager2/doc/download/

  Or, install FlowPlayer module (http://drupal.org/project/flowplayer) to use
  Flowplayer. Or, install jPlayer module (http://drupal.org/project/jplayer) to
  use jPlayer.

  Create a new folder called "player" under the directory "sites/all/libraries".
  Unzip the audio players directly into the "player" folder.

  The resulting folder structure should resemble the following (you may need to
  rename the folders and files to match):

  The standalone WordPress player should be at:
  /sites/all/libraries/player/audio-player/player.swf

  The XSPF slim player should be at:
  /sites/all/libraries/player/xspf_player_slim.swf

  The XSPF button player should be at:
  /sites/all/libraries/player/button/musicplayer.swf

  The Premium Beat single track player should be at:
  /sites/all/libraries/player/playersinglepackage/playerSingle.swf

  The Premium Beat single track thin player should be at:
  /sites/all/libraries/player/OriginalThinMusicPlayer.swf

  The Premium Beat single track mini player should be at:
  /sites/all/libraries/player/LWMusicPlayer.swf

- (optional) To use an alternate player that was added, choose the audio player
  from the configuration page.

Documentation
-------------

Additional documentation is located in the Wiki:
https://github.com/backdrop-contrib/audiofield/wiki/Documentation

Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/audiofield/issues

Current Maintainers
-------------------

- Cathy Theys (https://github.com/YesCT)
- Seeking additional maintainers

Credits
-------

- Ported to Backdrop CMS by Cathy Theys (https://github.com/YesCT).
- Maintained for Drupal by josipsaric (https://www.drupal.org/u/tamerzg).
- Maintained for Drupal by Tamer Zoubi (https://www.drupal.org/u/josipsaric).
- Originally written for Drupal by Tamer Zoubi (https://www.drupal.org/u/tamerzg).

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
