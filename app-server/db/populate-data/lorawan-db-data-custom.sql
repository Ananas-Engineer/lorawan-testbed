PGDMP     !                    y         
   lorawan-db    12.9    12.9 5               0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false                       0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false                       0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false                       1262    18358 
   lorawan-db    DATABASE     |   CREATE DATABASE "lorawan-db" WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'en_US.utf8' LC_CTYPE = 'en_US.utf8';
    DROP DATABASE "lorawan-db";
                root    false            �          0    17455    cache_inval_bgw_job 
   TABLE DATA           9   COPY _timescaledb_cache.cache_inval_bgw_job  FROM stdin;
    _timescaledb_cache          root    false    242   �2       �          0    17458    cache_inval_extension 
   TABLE DATA           ;   COPY _timescaledb_cache.cache_inval_extension  FROM stdin;
    _timescaledb_cache          root    false    243   3       �          0    17452    cache_inval_hypertable 
   TABLE DATA           <   COPY _timescaledb_cache.cache_inval_hypertable  FROM stdin;
    _timescaledb_cache          root    false    241   23       �          0    16990 
   hypertable 
   TABLE DATA             COPY _timescaledb_catalog.hypertable (id, schema_name, table_name, associated_schema_name, associated_table_prefix, num_dimensions, chunk_sizing_func_schema, chunk_sizing_func_name, chunk_target_size, compression_state, compressed_hypertable_id, replication_factor) FROM stdin;
    _timescaledb_catalog          root    false    210   O3       �          0    17076    chunk 
   TABLE DATA              COPY _timescaledb_catalog.chunk (id, hypertable_id, schema_name, table_name, compressed_chunk_id, dropped, status) FROM stdin;
    _timescaledb_catalog          root    false    219   l3       �          0    17041 	   dimension 
   TABLE DATA           �   COPY _timescaledb_catalog.dimension (id, hypertable_id, column_name, column_type, aligned, num_slices, partitioning_func_schema, partitioning_func, interval_length, integer_now_func_schema, integer_now_func) FROM stdin;
    _timescaledb_catalog          root    false    215   �3       �          0    17060    dimension_slice 
   TABLE DATA           a   COPY _timescaledb_catalog.dimension_slice (id, dimension_id, range_start, range_end) FROM stdin;
    _timescaledb_catalog          root    false    217   �3       �          0    17098    chunk_constraint 
   TABLE DATA           �   COPY _timescaledb_catalog.chunk_constraint (chunk_id, dimension_slice_id, constraint_name, hypertable_constraint_name) FROM stdin;
    _timescaledb_catalog          root    false    220   �3       �          0    17132    chunk_data_node 
   TABLE DATA           [   COPY _timescaledb_catalog.chunk_data_node (chunk_id, node_chunk_id, node_name) FROM stdin;
    _timescaledb_catalog          root    false    223   �3       �          0    17116    chunk_index 
   TABLE DATA           o   COPY _timescaledb_catalog.chunk_index (chunk_id, index_name, hypertable_id, hypertable_index_name) FROM stdin;
    _timescaledb_catalog          root    false    222   �3       �          0    17268    compression_chunk_size 
   TABLE DATA             COPY _timescaledb_catalog.compression_chunk_size (chunk_id, compressed_chunk_id, uncompressed_heap_size, uncompressed_toast_size, uncompressed_index_size, compressed_heap_size, compressed_toast_size, compressed_index_size, numrows_pre_compression, numrows_post_compression) FROM stdin;
    _timescaledb_catalog          root    false    235   4       �          0    17197    continuous_agg 
   TABLE DATA           �   COPY _timescaledb_catalog.continuous_agg (mat_hypertable_id, raw_hypertable_id, user_view_schema, user_view_name, partial_view_schema, partial_view_name, bucket_width, direct_view_schema, direct_view_name, materialized_only) FROM stdin;
    _timescaledb_catalog          root    false    229   74       �          0    17228 +   continuous_aggs_hypertable_invalidation_log 
   TABLE DATA           �   COPY _timescaledb_catalog.continuous_aggs_hypertable_invalidation_log (hypertable_id, lowest_modified_value, greatest_modified_value) FROM stdin;
    _timescaledb_catalog          root    false    231   T4       �          0    17218 &   continuous_aggs_invalidation_threshold 
   TABLE DATA           h   COPY _timescaledb_catalog.continuous_aggs_invalidation_threshold (hypertable_id, watermark) FROM stdin;
    _timescaledb_catalog          root    false    230   q4       �          0    17232 0   continuous_aggs_materialization_invalidation_log 
   TABLE DATA           �   COPY _timescaledb_catalog.continuous_aggs_materialization_invalidation_log (materialization_id, lowest_modified_value, greatest_modified_value) FROM stdin;
    _timescaledb_catalog          root    false    232   �4       �          0    17249    hypertable_compression 
   TABLE DATA           �   COPY _timescaledb_catalog.hypertable_compression (hypertable_id, attname, compression_algorithm_id, segmentby_column_index, orderby_column_index, orderby_asc, orderby_nullsfirst) FROM stdin;
    _timescaledb_catalog          root    false    234   �4       �          0    17012    hypertable_data_node 
   TABLE DATA           x   COPY _timescaledb_catalog.hypertable_data_node (hypertable_id, node_hypertable_id, node_name, block_chunks) FROM stdin;
    _timescaledb_catalog          root    false    211   �4       �          0    17189    metadata 
   TABLE DATA           R   COPY _timescaledb_catalog.metadata (key, value, include_in_telemetry) FROM stdin;
    _timescaledb_catalog          root    false    228   �4       �          0    17283 
   remote_txn 
   TABLE DATA           Y   COPY _timescaledb_catalog.remote_txn (data_node_name, remote_transaction_id) FROM stdin;
    _timescaledb_catalog          root    false    236   75       �          0    17026 
   tablespace 
   TABLE DATA           V   COPY _timescaledb_catalog.tablespace (id, hypertable_id, tablespace_name) FROM stdin;
    _timescaledb_catalog          root    false    213   T5       �          0    17146    bgw_job 
   TABLE DATA           �   COPY _timescaledb_config.bgw_job (id, application_name, schedule_interval, max_runtime, max_retries, retry_period, proc_schema, proc_name, owner, scheduled, hypertable_id, config) FROM stdin;
    _timescaledb_config          root    false    225   q5                 0    18367    PROFILE 
   TABLE DATA           [   COPY public."PROFILE" (email, phone_number, password, type, _id, display_name) FROM stdin;
    public          root    false    253   �5                 0    18386    ADMIN 
   TABLE DATA           4   COPY public."ADMIN" (profile_id, title) FROM stdin;
    public          root    false    255   �5                 0    18394    CUSTOMER 
   TABLE DATA           0   COPY public."CUSTOMER" (profile_id) FROM stdin;
    public          root    false    256   �5                 0    18420    BOARD 
   TABLE DATA           @   COPY public."BOARD" (_id, display_name, profile_id) FROM stdin;
    public          root    false    261   �5                 0    18447    ENDDEV 
   TABLE DATA           �   COPY public."ENDDEV" (_id, display_name, dev_id, dev_addr, join_eui, dev_eui, dev_type, dev_brand, dev_model, dev_band) FROM stdin;
    public          root    false    266   6                 0    18458    SENSOR 
   TABLE DATA           >   COPY public."SENSOR" (enddev_id, _id, sensor_key) FROM stdin;
    public          root    false    268   6                 0    18431    WIDGET 
   TABLE DATA           L   COPY public."WIDGET" (_id, display_name, config_dict, board_id) FROM stdin;
    public          root    false    263   <6                 0    18440 	   BELONG_TO 
   TABLE DATA           ;   COPY public."BELONG_TO" (widget_id, sensor_id) FROM stdin;
    public          root    false    264   Y6                 0    18485    ENDDEV_PAYLOAD 
   TABLE DATA           X   COPY public."ENDDEV_PAYLOAD" (_id, recv_timestamp, payload_data, enddev_id) FROM stdin;
    public          root    false    273   v6                 0    18474    UNIT 
   TABLE DATA           A   COPY public."UNIT" (_id, sensor_key, dev_type, uint) FROM stdin;
    public          root    false    271   �6                 0    18467    HAS_UNIT 
   TABLE DATA           8   COPY public."HAS_UNIT" (sensor_id, unit_id) FROM stdin;
    public          root    false    269   �6       	          0    18404    NOTIFICATION 
   TABLE DATA           P   COPY public."NOTIFICATION" (_id, title, content, updated_timestamp) FROM stdin;
    public          root    false    258   �6       
          0    18413    NOTIFY 
   TABLE DATA           7   COPY public."NOTIFY" (profile_id, noti_id) FROM stdin;
    public          root    false    259   �6                 0    18497    OWN 
   TABLE DATA           6   COPY public."OWN" (profile_id, enddev_id) FROM stdin;
    public          root    false    274   7                   0    0    chunk_constraint_name    SEQUENCE SET     R   SELECT pg_catalog.setval('_timescaledb_catalog.chunk_constraint_name', 1, false);
          _timescaledb_catalog          root    false    221            !           0    0    chunk_id_seq    SEQUENCE SET     I   SELECT pg_catalog.setval('_timescaledb_catalog.chunk_id_seq', 1, false);
          _timescaledb_catalog          root    false    218            "           0    0    dimension_id_seq    SEQUENCE SET     M   SELECT pg_catalog.setval('_timescaledb_catalog.dimension_id_seq', 1, false);
          _timescaledb_catalog          root    false    214            #           0    0    dimension_slice_id_seq    SEQUENCE SET     S   SELECT pg_catalog.setval('_timescaledb_catalog.dimension_slice_id_seq', 1, false);
          _timescaledb_catalog          root    false    216            $           0    0    hypertable_id_seq    SEQUENCE SET     N   SELECT pg_catalog.setval('_timescaledb_catalog.hypertable_id_seq', 1, false);
          _timescaledb_catalog          root    false    209            %           0    0    bgw_job_id_seq    SEQUENCE SET     M   SELECT pg_catalog.setval('_timescaledb_config.bgw_job_id_seq', 1000, false);
          _timescaledb_config          root    false    224            &           0    0    BOARD__id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public."BOARD__id_seq"', 1, false);
          public          root    false    260            '           0    0    ENDDEV_PAYLOAD__id_seq    SEQUENCE SET     G   SELECT pg_catalog.setval('public."ENDDEV_PAYLOAD__id_seq"', 1, false);
          public          root    false    272            (           0    0    ENDDEV__id_seq    SEQUENCE SET     ?   SELECT pg_catalog.setval('public."ENDDEV__id_seq"', 1, false);
          public          root    false    265            )           0    0    NOTIFICATION__id_seq    SEQUENCE SET     E   SELECT pg_catalog.setval('public."NOTIFICATION__id_seq"', 1, false);
          public          root    false    257            *           0    0    PROFILE__id_seq    SEQUENCE SET     @   SELECT pg_catalog.setval('public."PROFILE__id_seq"', 1, false);
          public          root    false    254            +           0    0    SENSOR__id_seq    SEQUENCE SET     ?   SELECT pg_catalog.setval('public."SENSOR__id_seq"', 1, false);
          public          root    false    267            ,           0    0    UNIT__id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public."UNIT__id_seq"', 1, false);
          public          root    false    270            -           0    0    WIDGET__id_seq    SEQUENCE SET     ?   SELECT pg_catalog.setval('public."WIDGET__id_seq"', 1, false);
          public          root    false    262            �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �      x������ � �      �   B   x�K�(�/*IM�/-�L�42IM1�LJ�5�H��5I�0�M2M5�5I40�H5126KL�,����� #U2      �      x������ � �      �      x������ � �      �      x������ � �            x������ � �            x������ � �            x������ � �            x������ � �            x������ � �            x������ � �            x������ � �            x������ � �            x������ � �            x������ � �            x������ � �      	      x������ � �      
      x������ � �            x������ � �     