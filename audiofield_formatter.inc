<?php
// $Id$:
/**@file
 * Theme function for 'embedded' audio.
 */
function theme_audiofield_formatter_audiofield_embedded($variables) {
global $user;
//var_dump($variables);
$file = $variables['']['#file'];
//Don't render player if there is no file.
  if (!$file) {
    return '';
  }

  //$info = pathinfo($element['#item']['filename']);
  //$op = $info['extension'];
  $op='mp3';
  $audiofile=file_create_url($file->uri);
  $output= audiofield_get_player($audiofile, $op);
	
	//If user is file owner check for download permission and display download link
	if($user->uid==$file->uid && user_access('download own audio files')){
	   $output.='<div class="audio-download"><b>Download:</b>'.theme('file_link', $variables).'</div>';
    }
	elseif(user_access('download all audio files')){
	//If user has permission to download all audio files, then display download link
		$output.='<div class="audio-download"><b>Download:</b>'.theme('file_link', $variables).'</div>';
	}
   
   return $output;
}
