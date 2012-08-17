<?php
/**
 * @file
 * Implement an audio field, based on the file module's file field.
 */

/**
 * Implements hook_field_prepare_view().
 */
function audiofield_field_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items) {
  //TODO: Check this:
  //  Remove files specified to not be displayed.
  foreach ($entities as $id => $entity) {
    foreach ($items[$id] as $delta => $item) {
      if (!file_field_displayed($item, $field)) {
        unset($items[$id][$delta]);
      }
      // Ensure consecutive deltas.
      $items[$id] = array_values($items[$id]);
    }
  }
}

/**
 * Implements hook_field_is_empty().
 */
function audiofield_field_is_empty($item, $field) {
  return file_field_is_empty($item, $field);
}

/**
 * Implements hook_field_widget_info().
 */
function audiofield_field_widget_info() {
  return array(
    'audiofield_widget' => array(
      'label' => t('Audio Upload'),
      'field types' => array('file'),
      'settings' => array(
        'progress_indicator' => 'throbber',
        //'file_extensions' => 'mp3',
      ),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
        'default value' => FIELD_BEHAVIOR_NONE,
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function audiofield_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {

  // Add display_field setting to field because file_field_widget_form() assumes it is set.
  $field['settings']['display_field'] = 0;

  $elements = file_field_widget_form($form, $form_state, $field, $instance, $langcode, $items, $delta, $element);
  $settings = $instance['settings'];

  foreach (element_children($elements) as $delta) {
      $elements[$delta]['#process'] = array('audiofield_field_widget_process');
  }
  if ($field['cardinality'] == 1) {
    // If there's only one field, return it as delta 0.
    if (empty($elements[0]['#default_value']['fid'])) {
      $elements[0]['#description'] = theme('file_upload_help', array('description' => $instance['description'], 'upload_validators' => $elements[0]['#upload_validators']));
    }
  }
  else {
    $elements['#file_upload_description'] = theme('file_upload_help', array('upload_validators' => $elements[0]['#upload_validators']));
  }

  return $elements;
}

/**
 * An element #process callback for the audiofield_widget field type.
 *
 * Display audio player in node edit mode
 */
function audiofield_field_widget_process($element, &$form_state, $form) {
  $fid = isset($element['#value']['fid']) ? $element['#value']['fid'] : 0;
  $element = file_managed_file_process($element, $form_state, $form);
  if ($fid && $element['#file']) {
    $audiofile=file_create_url($element['#file']->uri);
    $info = pathinfo($audiofile);
    $op = $info['extension'];
	$element['filename'] = array(
      '#type' => 'markup',
      '#markup' => audiofield_get_player($audiofile, $op),
      '#weight' => -10,
    );
  }
  return $element;
}

/**
 * Implements hook_field_formatter_info().
 */
function audiofield_field_formatter_info() {
  $formatters = array(
    'audiofield_embedded' => array(
      'label' => t('Audio'),
      'field types' => array('file'),
      'description' => t('Displays audio embedded in a web page.'),
    ),
  );

  return $formatters;
}

/**
 * Implements hook_field_formatter_view().
 TODO: Can implement playlists to group audios hold in multiple valued fields
 */
function audiofield_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $elements = array();

  foreach ($items as $delta => $item) {
    $elements[] =  array( '#markup' => theme( 'audiofield_formatter_audiofield_embedded', array( 'file' => (object)$item )));    	
  }

  return $elements;
}
